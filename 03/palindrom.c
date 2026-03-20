#include <stdio.h>

/*
Zadanie:
Napisz program, który wczytuje jedną liczbę całkowitą nieujemną
i sprawdza, czy jest ona palindromem, tzn. czy czytana od lewej do prawej
i od prawej do lewej jest taka sama.

Dane wejściowe:
- jedna liczba całkowita nieujemna

Dane wyjściowe:
- TAK, jeśli liczba jest palindromem
- NIE, jeśli liczba nie jest palindromem

Przykład:
Wejście:
12321

Wyjście:
TAK
*/

int main(void) {
    int n, oryginal, odwrocona = 0, cyfra;

    scanf("%d", &n);

    oryginal = n;

    do {
        cyfra = n % 10;
        odwrocona = odwrocona * 10 + cyfra;
        n /= 10;
    } while (n > 0);

    if (oryginal == odwrocona) {
        printf("TAK\n");
    } else {
        printf("NIE\n");
    }

    return 0;
}