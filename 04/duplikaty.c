#include <stdio.h>

int main() {
    int N;
    int a[100];
    int b[100];
    int M = 0;

    scanf("%d", &N);

    int *p = a;

    for(int i = 0; i < N; i++) {
        scanf("%d", p + i);
    }

    for(int i = 0; i < N; i++) {

        int *current = a + i;
        int exists = 0;

        for(int j = 0; j < M; j++) {
            if(*(b + j) == *current) {
                exists = 1;
                break;
            }
        }

        if(!exists) {
            *(b + M) = *current;
            M++;
        }
    }

    printf("%d\n", M);

    for(int i = 0; i < M; i++) {
        printf("%d\n", *(b + i));
    }

    return 0;
}