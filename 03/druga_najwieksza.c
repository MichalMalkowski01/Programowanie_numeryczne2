#include <stdio.h>
#include <limits.h>

/*
Zadanie:
Napisz program, który wczytuje liczbę naturalną N, a następnie N liczb całkowitych.
Program ma znaleźć drugą największą różną wartość spośród podanych liczb.

Dane wejściowe:
- w pierwszym wierszu liczba N
- następnie N liczb całkowitych

Dane wyjściowe:
- druga największa różna liczba

Uwagi:
- można założyć, że w danych istnieją co najmniej dwie różne wartości

Przykład:
Wejście:
6
4 9 2 9 7 5

Wyjście:
7
*/

int main(void) {
    int N, x;
    int max1 = INT_MIN;
    int max2 = INT_MIN;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);

        if (x > max1) {
            max2 = max1;
            max1 = x;
        } else if (x > max2 && x < max1) {
            max2 = x;
        }
    }

    printf("%d\n", max2);

    return 0;
}