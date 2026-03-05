#include <stdio.h>

int main() {
    double liczba;

    printf("Podaj liczbe rzeczywista: ");
    scanf("%lf", &liczba);

    printf("%f\n", liczba);

    printf("%.10f\n", liczba);

    printf("%10.2f\n", liczba);

    printf("%e\n", liczba);

    printf("%.3e\n", liczba);

    return 0;
}