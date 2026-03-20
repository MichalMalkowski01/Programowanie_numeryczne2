import math
import matplotlib.pyplot as plt
import numpy as np
def f(x):
    return x**(1/2)

def df(x):
    return 1 / (2 * x**(1/2))

a = 4

x = 2

approx = f(a) + df(a) * (x - a)
exact = f(x)
error = abs(exact - approx)

print("Przybliżenie liniowe sqrt(2):", approx)
print("Dokładna wartość sqrt(2):", exact)
print("Błąd bezwzględny:", error)
X = np.linspace(0, 10, 100)
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