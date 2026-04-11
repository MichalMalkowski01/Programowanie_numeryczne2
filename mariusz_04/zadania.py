import math
import sympy as sp


# ==========================================================
# ZADANIE 1
# Dla metody bisekcji znajdź najmniejsze n takie, że eps < eps_n
# gdzie eps_n = |b-a| / 2^n
# ==========================================================
def zadanie1_bisekcja(a, b, eps):
    if eps <= 0:
        raise ValueError("eps musi być dodatnie")

    n = math.ceil(math.log2(abs(b - a) / eps))

    print("ZADANIE 1")
    print(f"a = {a}, b = {b}, eps = {eps}")
    print("Szukamy najmniejszego n, dla którego:")
    print("    |b-a| / 2^n < eps")
    print(f"n = ceil(log2(|b-a| / eps)) = {n}")
    print()

    return n


# ==========================================================
# ZADANIE 2
# Wykaż wzory na kolejny krok regula falsi
# ==========================================================
def zadanie2_regula_falsi_wyprowadzenie():
    print("ZADANIE 2")

    a, b, xn = sp.symbols('a b xn')
    fa, fb, fxn = sp.symbols('fa fb fxn')

    # Przypadek 1: prosta przez (a, fa) i (xn, fxn)
    x = sp.symbols('x')
    y1 = fa + (fxn - fa) / (xn - a) * (x - a)

    rozw1 = sp.solve(sp.Eq(y1, 0), x)[0]
    rozw1 = sp.simplify(rozw1)

    print("Dla f(a) * f(xn) < 0 bierzemy punkty (a, f(a)) i (xn, f(xn))")
    print("Punkt przecięcia siecznej z osią OX:")
    print("x_(n+1) =", rozw1)
    print("Po uporządkowaniu:")
    print("x_(n+1) = (xn*f(a) - a*f(xn)) / (f(a) - f(xn))")
    print()

    # Przypadek 2: prosta przez (xn, fxn) i (b, fb)
    y2 = fxn + (fb - fxn) / (b - xn) * (x - xn)

    rozw2 = sp.solve(sp.Eq(y2, 0), x)[0]
    rozw2 = sp.simplify(rozw2)

    print("Dla f(b) * f(xn) < 0 bierzemy punkty (xn, f(xn)) i (b, f(b))")
    print("Punkt przecięcia siecznej z osią OX:")
    print("x_(n+1) =", rozw2)
    print("Po uporządkowaniu:")
    print("x_(n+1) = (b*f(xn) - xn*f(b)) / (f(xn) - f(b))")
    print()


# ==========================================================
# ZADANIE 3a
# Policz sqrt(2) metodą Newtona z dokładnością do 5 miejsc po przecinku
# f(x) = x^2 - 2
# x_(n+1) = x_n - f(x_n)/f'(x_n)
# ==========================================================
def zadanie3a_newton_sqrt2(x0=1.5, tol=1e-6, max_iter=20):
    def f(x):
        return x**2 - 2

    def df(x):
        return 2*x

    x = x0

    print("ZADANIE 3a")
    print("Liczymy sqrt(2) metodą Newtona dla f(x) = x^2 - 2")
    print(f"Punkt startowy: x0 = {x0}")
    print()

    for n in range(max_iter):
        x_new = x - f(x) / df(x)
        print(f"x_{n+1} = {x_new}")

        if abs(x_new - x) < tol:
            print()
            print("Wynik do 5 miejsc po przecinku:")
            print(f"sqrt(2) ≈ {x_new:.5f}")
            print()
            return x_new

        x = x_new

    print()
    print("Nie osiągnięto zadanej dokładności.")
    print()
    return x


# ==========================================================
# ZADANIE 3b
# Przykład funkcji, która przy złym wyborze punktu początkowego się zapętla
# ==========================================================
def zadanie3b_zapetlenie_newtona(x0=0, max_iter=10):
    def f(x):
        return x**3 - 2*x + 2

    def df(x):
        return 3*x**2 - 2

    x = x0

    print("ZADANIE 3b")
    print("Przykładowa funkcja:")
    print("f(x) = x^3 - 2x + 2")
    print(f"Start: x0 = {x0}")
    print("Kolejne iteracje Newtona:")
    print(f"x_0 = {x}")

    for n in range(max_iter):
        x_new = x - f(x) / df(x)
        print(f"x_{n+1} = {x_new}")
        x = x_new

    print()
    print("Dla x0 = 0 metoda wpada w cykl 0 -> 1 -> 0 -> 1 -> ...")
    print("To jest przykład zapętlenia przy złym wyborze punktu początkowego.")
    print()


# ==========================================================
# URUCHOMIENIE
# ==========================================================
zadanie1_bisekcja(a=1, b=2, eps=1e-5)
zadanie2_regula_falsi_wyprowadzenie()
zadanie3a_newton_sqrt2(x0=1.5, tol=1e-6)
zadanie3b_zapetlenie_newtona(x0=0, max_iter=8)