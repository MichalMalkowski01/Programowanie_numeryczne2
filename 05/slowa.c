#include <stdio.h>

int main() {
    int N;
    char slowo[100];
    char *p;
    int suma = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int dlugosc = 0;

        scanf("%s", slowo);

        p = slowo;
        while (*p != '\0') {
            dlugosc++;
            p++;
        }

        suma += dlugosc;
    }

    printf("%.1f\n", (double)suma / N);

    return 0;
}