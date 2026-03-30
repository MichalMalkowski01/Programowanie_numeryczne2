#include <stdio.h>

int main(void) {
    int x = 42;
    int *wsk = &x;

    printf("Adres wskaźnika: %p\n", &wsk);
    printf("Adres przechowywany przez wskaznik: %p\n", wsk);
    printf("Wartosc pod tym adresem: %d\n", *wsk);

    return 0;
}