#include <stdio.h>

int main() {
    char napis[101];
    char *p;
    int dlugosc = 0;

    scanf("%s", napis);

    p = napis;
    while (*p != '\0') {
        dlugosc++;
        p++;
    }

    printf("%d\n", dlugosc);

    return 0;
}