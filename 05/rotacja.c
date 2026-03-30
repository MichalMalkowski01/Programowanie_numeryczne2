#include <stdio.h>

int main() {
    int N, k;
    int a[100], wynik[100];
    int *p, *q;

    scanf("%d %d", &N, &k);

    for (p = a; p < a + N; p++) {
        scanf("%d", p);
    }

    k = k % N;

    for (p = a; p < a + N; p++) {
        q = wynik + ((p - a + k) % N);
        *q = *p;
    }

    for (p = wynik; p < wynik + N; p++) {
        printf("%d", *p);
        if (p < wynik + N - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}