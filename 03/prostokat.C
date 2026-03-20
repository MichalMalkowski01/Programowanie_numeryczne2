#include <stdio.h>

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == M - 1 || j == 0 || j == N - 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}