#include <stdio.h>

int main(void) {
    int N;
    double x, suma = 0.0;

    printf("Podaj N: ");
    while (scanf("%d", &N) != 1 || N <= 0) {
        printf("Blad! Podaj liczbe calkowita dodatnia: ");
        while (getchar() != '\n'); // czyszczenie bufora
    }

    for (int i = 0; i < N; i++) {
        printf("Podaj liczbe %d: ", i + 1);

        while (scanf("%lf", &x) != 1) {
            printf("Blad! Podaj liczbe: ");
            while (getchar() != '\n'); // usuwanie zlego inputu
        }

        suma += x;
    }

    printf("Srednia = %.8g\n", suma / N);

    return 0;
}