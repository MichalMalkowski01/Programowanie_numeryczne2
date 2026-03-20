#include <stdio.h>

/*
Zadanie:
Napisz program, który wczytuje liczbę naturalną N, a następnie N liczb całkowitych.
Program ma policzyć, ile spośród wczytanych liczb jest liczbami pierwszymi.

Dane wejściowe:
- w pierwszym wierszu liczba N
- następnie N liczb całkowitych

Dane wyjściowe:
- liczba elementów, które są liczbami pierwszymi

Przykład:
Wejście:
5
2 4 5 8 11

Wyjście:
3
*/

int czy_pierwsza(int x) {
    if (x < 2) {
        return 0;
    }

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    int N, x;
    int licznik = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        if (czy_pierwsza(x)) {
            licznik++;
        }
    }

    printf("%d\n", licznik);

    return 0;
}