#include <stdio.h>
#include <math.h>

int main() {
    double a, b;
    printf("Podaj dwie liczby: ");
    scanf("%lf %lf", &a, &b);

    double suma = a + b;
    double iloczyn = a * b;

    printf("Suma: %.2lf\n", suma);
    printf("Iloczyn: %.2lf\n", iloczyn);

    return 0;
}