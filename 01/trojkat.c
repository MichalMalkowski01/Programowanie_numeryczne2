#include <stdio.h>

int main() {
    double a, b, c;

    printf("Podaj trzy liczby rzeczywiste: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a + b > c && a + c > b && b + c > a) {
        printf("TAK\n");
    } else {
        printf("NIE\n");
    }

    return 0;
}