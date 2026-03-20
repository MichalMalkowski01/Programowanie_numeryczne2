#include <stdio.h>

int main(void) {
    int N;
    double x, suma = 0.0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%lf", &x);
        suma += x;
    }

    printf("Srednia = %.8g\n", suma / N);

    return 0;
}