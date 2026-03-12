import math
import matplotlib.pyplot as plt
import numpy as np
def f(x):
    return x**(1/3)

def df(x):
    return 1 / (3 * x**(2/3))

a = 27

x = 25

approx = f(a) + df(a) * (x - a)
exact = f(x)
error = abs(exact - approx)

print("Przybliżenie liniowe:", approx)
print("Dokładna wartość:", exact)
print("Błąd bezwzględny:", error)
X = np.linspace(10, 50, 100)
Y = f(X)
plt.plot(X, Y, label='f(x) = sqrt(x)')
plt.scatter([a], [f(a)], color='red', label='Punkt a')
plt.scatter([x], [f(x)], color='green', label='Punkt x')
plt.plot(X, [f(a) + df(a) * (xi - a) for xi in X], color='blue', label='Przybliżenie liniowe')
plt.legend()
plt.title('Aproksymacja liniowa funkcji sqrt(x)')
plt.xlabel('x')
plt.ylabel('f(x)')  
plt.show()