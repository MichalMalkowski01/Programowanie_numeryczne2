#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    
    int i, j;
    for (i = 1; i <= N; i++)
    {
        int n = i;
        for (j = 1; j <= N; j++)
        {
            printf("%d ", n);
            n = n + i;
        }
        printf("\n");
    }

    return 0;
}