#include <stdio.h>

int main() {
    double a, b, c, max;
    printf("Podaj trzy liczby rzeczywiste: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    max = a;

    if (b > max) {
        max = b;
    }

    if (c > max) {
        max = c;
    }

    printf("Max z 3 liczb: %f\n", max);

    return 0;
}