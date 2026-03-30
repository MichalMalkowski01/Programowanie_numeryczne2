#include <stdio.h>

/*
Zadanie:
Napisz program, który:
1. Wczyta liczbę N
2. Wczyta N liczb całkowitych do tablicy
3. Obliczy średnią arytmetyczną używając wskaźników
4. Wypisze wynik jako liczbę zmiennoprzecinkową
*/

int main() {
    int N;
    int tab[100];
    int *p;
    int suma = 0;
    float srednia;

    scanf("%d", &N);

    p = tab;
    for (int i = 0; i < N; i++) {
        scanf("%d", p);
        p++;
    }

    p = tab;
    for (int i = 0; i < N; i++) {
        suma += *p;
        p++;
    }

    srednia = (float)suma / N;

    printf("%.2f\n", srednia);

    return 0;
}