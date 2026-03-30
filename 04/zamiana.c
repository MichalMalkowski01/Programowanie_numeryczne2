#include <stdio.h>

/*
Zadanie:
Napisz funkcję:
    void zamien(int *a, int *b);
która zamienia miejscami dwie liczby.

Następnie napisz program, który:
1. Wczyta dwie liczby całkowite
2. Wywoła funkcję zamien
3. Wypisze liczby po zamianie
*/

void zamien(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;

    scanf("%d %d", &x, &y);

    zamien(&x, &y);

    printf("%d %d\n", x, y);

    return 0;
}