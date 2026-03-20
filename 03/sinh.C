#include <stdio.h>
#include <math.h>

int main(void) {
    double x;
    scanf("%lf", &x);

    double suma = 0.0;
    double wyraz = x;   // pierwszy wyraz: x^(2*0+1)/(2*0+1)! = x
    int n = 0;

    while (fabs(wyraz) > 1e-6) {
        suma += wyraz;
        n++;
        wyraz *= x * x / ((2.0 * n) * (2.0 * n + 1.0));
    }

    printf("%.6f\n", suma);

    return 0;
}