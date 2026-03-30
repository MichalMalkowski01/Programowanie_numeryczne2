#include <stdio.h>

int main() {
    int N;
    int a[100];
    int *p;

    scanf("%d", &N);

    p = a;
    for(int i = 0; i < N; i++) {
        scanf("%d", p);
        p++;
    }

    p--;

    for(int i = 0; i < N; i++) {
        printf("%d ", *p);
        p--;
    }

    return 0;
}