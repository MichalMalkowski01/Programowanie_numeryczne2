import numpy as np

def weighted_linear_fit(x, y, sigma):
    """
    Ważona regresja liniowa y = a*x + b metodą najmniejszych kwadratów.

    Parametry:
        x, y, sigma - tablice danych pomiarowych

    Zwraca:
        a, b, sigma_a, sigma_b, chi2, chi2_red
    """
    x = np.asarray(x, dtype=float)
    y = np.asarray(y, dtype=float)
    sigma = np.asarray(sigma, dtype=float)

    if len(x) != len(y) or len(y) != len(sigma):
        raise ValueError("x, y i sigma muszą mieć tę samą długość.")
    if len(x) < 2:
        raise ValueError("Potrzeba co najmniej 2 punktów do dopasowania prostej.")
    if np.any(sigma <= 0):
        raise ValueError("Wszystkie sigma muszą być dodatnie.")

    w = 1.0 / sigma**2

    S = np.sum(w)
    Sx = np.sum(x * w)
    Sy = np.sum(y * w)
    Sxx = np.sum(x**2 * w)
    Sxy = np.sum(x * y * w)

    Delta = S * Sxx - Sx**2
    if np.isclose(Delta, 0):
        raise ValueError("Delta = 0, nie da się wyznaczyć współczynników.")

    a = (S * Sxy - Sx * Sy) / Delta
    b = (Sxx * Sy - Sx * Sxy) / Delta

    sigma_a = np.sqrt(S / Delta)
    sigma_b = np.sqrt(Sxx / Delta)

    y_fit = a * x + b
    residuals = y - y_fit

    chi2 = np.sum((residuals / sigma) ** 2)
    dof = len(x) - 2
    chi2_red = chi2 / dof if dof > 0 else np.nan

    return a, b, sigma_a, sigma_b, chi2, chi2_red


def compute_r2(x, y, a, b):
    """
    Współczynnik determinacji R^2.
    """
    x = np.asarray(x, dtype=float)
    y = np.asarray(y, dtype=float)

    y_fit = a * x + b
    y_mean = np.mean(y)

    ss_res = np.sum((y - y_fit) ** 2)
    ss_tot = np.sum((y - y_mean) ** 2)

    if np.isclose(ss_tot, 0):
        return np.nan

    return 1.0 - ss_res / ss_tot


def iterative_outlier_rejection(x, y, sigma, threshold=3.0, max_iter=20, verbose=True):
    """
    Iteracyjna regresja liniowa z odrzucaniem punktów odstających.

    Kroki:
    1. Dopasuj prostą y = a*x + b
    2. Policz reszty znormalizowane r_i = (y_i - (a*x_i+b))/sigma_i
    3. Usuń punkty z |r_i| > threshold
    4. Powtarzaj aż nie będzie nowych odrzuceń

    Zwraca słownik z pełnymi wynikami.
    """
    x = np.asarray(x, dtype=float)
    y = np.asarray(y, dtype=float)
    sigma = np.asarray(sigma, dtype=float)

    if len(x) != len(y) or len(y) != len(sigma):
        raise ValueError("x, y i sigma muszą mieć tę samą długość.")
    if len(x) < 3:
        raise ValueError("Potrzeba co najmniej 3 punktów do iteracyjnej procedury.")

    mask = np.ones(len(x), dtype=bool)
    removed_indices = []

    history = []

    for iteration in range(1, max_iter + 1):
        x_curr = x[mask]
        y_curr = y[mask]
        sigma_curr = sigma[mask]

        if len(x_curr) < 3:
            raise ValueError("Zostało za mało punktów po odrzucaniu outlierów.")

        a, b, sigma_a, sigma_b, chi2, chi2_red = weighted_linear_fit(x_curr, y_curr, sigma_curr)
        r2 = compute_r2(x_curr, y_curr, a, b)

        residuals_norm = (y_curr - (a * x_curr + b)) / sigma_curr
        outliers_local = np.where(np.abs(residuals_norm) > threshold)[0]

        history.append({
            "iteracja": iteration,
            "liczba_punktow": len(x_curr),
            "a": a,
            "b": b,
            "sigma_a": sigma_a,
            "sigma_b": sigma_b,
            "chi2": chi2,
            "chi2_red": chi2_red,
            "R2": r2,
            "liczba_odrzuconych_w_tej_iteracji": len(outliers_local)
        })

        if verbose:
            print(f"\nIteracja {iteration}")
            print(f"  liczba punktów: {len(x_curr)}")
            print(f"  a = {a:.6f} ± {sigma_a:.6f}")
            print(f"  b = {b:.6f} ± {sigma_b:.6f}")
            print(f"  chi^2 = {chi2:.6f}")
            print(f"  chi^2_red = {chi2_red:.6f}")
            print(f"  R^2 = {r2:.6f}")
            print(f"  outliery w tej iteracji: {len(outliers_local)}")

        # jeśli brak nowych outlierów -> koniec
        if len(outliers_local) == 0:
            final_x = x_curr
            final_y = y_curr
            final_sigma = sigma_curr
            final_residuals_norm = residuals_norm
            break

        # zamiana indeksów lokalnych na globalne
        global_indices = np.where(mask)[0][outliers_local]
        removed_indices.extend(global_indices.tolist())

        # odrzucamy te punkty
        mask[global_indices] = False

    else:
        # jeśli pętla dojdzie do max_iter
        final_x = x[mask]
        final_y = y[mask]
        final_sigma = sigma[mask]
        a, b, sigma_a, sigma_b, chi2, chi2_red = weighted_linear_fit(final_x, final_y, final_sigma)
        r2 = compute_r2(final_x, final_y, a, b)
        final_residuals_norm = (final_y - (a * final_x + b)) / final_sigma

    result = {
        "a": a,
        "b": b,
        "sigma_a": sigma_a,
        "sigma_b": sigma_b,
        "chi2": chi2,
        "chi2_red": chi2_red,
        "R2": r2,
        "x_final": final_x,
        "y_final": final_y,
        "sigma_final": final_sigma,
        "residuals_norm_final": final_residuals_norm,
        "removed_indices": sorted(set(removed_indices)),
        "n_removed": len(set(removed_indices)),
        "n_final": len(final_x),
        "history": history,
        "mask_final": mask.copy()
    }

    return result


if __name__ == "__main__":
    x = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], dtype=float)
    y = np.array([3.1, 5.0, 7.2, 9.1, 11.0, 13.2, 15.1, 40.0, 19.3, -5.0], dtype=float)
    sigma = np.array([0.3, 0.3, 0.4, 0.3, 0.3, 0.4, 0.3, 0.5, 0.4, 0.5], dtype=float)

    result = iterative_outlier_rejection(x, y, sigma, threshold=3.0, max_iter=20, verbose=True)

    print("\n" + "=" * 50)
    print("WYNIK KOŃCOWY")
    print("=" * 50)
    print(f"a = {result['a']:.6f} ± {result['sigma_a']:.6f}")
    print(f"b = {result['b']:.6f} ± {result['sigma_b']:.6f}")
    print(f"chi^2 = {result['chi2']:.6f}")
    print(f"chi^2_red = {result['chi2_red']:.6f}")
    print(f"R^2 = {result['R2']:.6f}")
    print(f"Liczba usuniętych punktów: {result['n_removed']}")
    print(f"Indeksy usuniętych punktów: {result['removed_indices']}")
    print(f"Liczba punktów końcowych: {result['n_final']}")