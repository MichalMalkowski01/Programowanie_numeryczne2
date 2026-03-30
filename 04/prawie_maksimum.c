#include <stdio.h>

int main() {
    int N, k;
    int a[100];

    scanf("%d %d", &N, &k);

    int *p = a;

    for(int i = 0; i < N; i++) {
        scanf("%d", p + i);
    }

    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N - 1 - i; j++) {

            int *x = a + j;
            int *y = a + j + 1;

            if(*x < *y) {
                int temp = *x;
                *x = *y;
                *y = temp;
            }
        }
    }

    printf("%d\n", *(a + k - 1));

    return 0;
}