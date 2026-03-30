#include <stdio.h>

/*
Zadanie:
Napisz program, który:
1. Wczyta liczbę N
2. Wczyta N liczb całkowitych do tablicy
3. Znajdzie największy element używając wskaźników
4. Wypisze największą wartość
*/

int main() {
    int N;
    int tab[100];
    int *p;
    int max;

    scanf("%d", &N);

    p = tab;
    for (int i = 0; i < N; i++) {
        scanf("%d", p);
        p++;
    }

    p = tab;
    max = *p;
    p++;

    for (int i = 1; i < N; i++) {
        if (*p > max) {
            max = *p;
        }
        p++;
    }

    printf("%d\n", max);

    return 0;
}