#include <stdio.h>

/*
Zadanie:
Napisz program, który wczytuje liczbę naturalną N i wypisuje N pierwszych
wyrazów ciągu Fibonacciego.

Ciąg Fibonacciego:
F0 = 0
F1 = 1
Fn = Fn-1 + Fn-2 dla n >= 2

Dane wejściowe:
- jedna liczba naturalna N

Dane wyjściowe:
- N pierwszych wyrazów ciągu Fibonacciego, rozdzielonych spacjami

Przykład:
Wejście:
7

Wyjście:
0 1 1 2 3 5 8
*/

int main(void) {
    int N;
    unsigned long long a = 0, b = 1, c;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            printf("%llu", a);
        } else if (i == 1) {
            printf(" %llu", b);
        } else {
            c = a + b;
            printf(" %llu", c);
            a = b;
            b = c;
        }
    }

    printf("\n");

    return 0;
}