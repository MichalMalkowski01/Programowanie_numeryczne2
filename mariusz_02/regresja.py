import numpy as np

x = np.array([1, 2, 3, 4], dtype=float)
y = np.array([2.1, 4.0, 5.9, 8.2], dtype=float)
sigma = np.array([0.2, 0.2, 0.3, 0.2], dtype=float)

w = 1.0 / sigma**2

S = np.sum(w)
Sx = np.sum(x * w)
Sy = np.sum(y * w)
Sxx = np.sum(x**2 * w)
Sxy = np.sum(x * y * w)

Delta = S * Sxx - Sx**2

a = (S * Sxy - Sx * Sy) / Delta
b = (Sxx * Sy - Sx * Sxy) / Delta

sigma_a = np.sqrt(S / Delta)
sigma_b = np.sqrt(Sxx / Delta)

print("Wyniki regresji liniowej:")
print(f"a = {a:.6f} ± {sigma_a:.6f}")
print(f"b = {b:.6f} ± {sigma_b:.6f}")