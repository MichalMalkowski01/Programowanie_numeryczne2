def neville_value(x_nodes, f_values, x0):
    n = len(x_nodes)
    p = f_values[:]

    for j in range(1, n):
        for i in range(n - j):
            p[i] = ((x_nodes[i + j] - x0) * p[i] +
                    (x0 - x_nodes[i]) * p[i + 1]) / (x_nodes[i + j] - x_nodes[i])

    return p[0]


def neville_coefficients(x_nodes, f_values):
    points = sorted(zip(x_nodes, f_values), key=lambda p: abs(p[0]), reverse=True)
    x = x_nodes
    f = f_values

    n = len(x)
    a = []

    current_f = f[:]
    a0 = neville_value(x, current_f, 0.0)
    a.append(a0)

    for j in range(1, n):
        for i in range(n - j):
            if x[i] == 0:
                raise ZeroDivisionError("Jeden z węzłów x[i] = 0, dzielenie niemożliwe.")
            current_f[i] = (current_f[i] - a[j - 1]) / x[i]

        a_j = neville_value(x[:n - j], current_f[:n - j], 0.0)
        a.append(a_j)

    return a


def polynomial_to_string(coeffs, eps=1e-12):
    """
    Zamienia listę współczynników na ładny zapis wielomianu.
    """
    terms = []

    for power, c in enumerate(coeffs):
        if abs(c) < eps:
            continue

        if abs(c - round(c)) < eps:
            c = int(round(c))

        if power == 0:
            terms.append(f"{c}")
        elif power == 1:
            if c == 1:
                terms.append("x")
            elif c == -1:
                terms.append("-x")
            else:
                terms.append(f"{c}x")
        else:
            if c == 1:
                terms.append(f"x^{power}")
            elif c == -1:
                terms.append(f"-x^{power}")
            else:
                terms.append(f"{c}x^{power}")

    if not terms:
        return "0"

    result = terms[0]
    for term in terms[1:]:
        if term.startswith("-"):
            result += " - " + term[1:]
        else:
            result += " + " + term

    return result


# =========================
# Zadanie 1a
# punkty: (-1, 6), (2, 3), (3, 10)
# =========================
x_a = [-1, 2, 3]
f_a = [6, 3, 10]

coeffs_a = neville_coefficients(x_a, f_a)
print("Zadanie 1a - współczynniki:", coeffs_a)
print("Zadanie 1a - wielomian:   L(x) =", polynomial_to_string(coeffs_a))


# =========================
# Zadanie 1b
# punkty: (-2, -11), (1, 1), (4, -5)
# =========================
x_b = [-2, 1, 4]
f_b = [-11, 1, -5]

coeffs_b = neville_coefficients(x_b, f_b)
print("Zadanie 1b - współczynniki:", coeffs_b)
print("Zadanie 1b - wielomian:   L(x) =", polynomial_to_string(coeffs_b))