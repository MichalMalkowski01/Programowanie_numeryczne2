#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int liczba_pierwsza;
    for (liczba_pierwsza = 2; N != 1;)
    {
        if (N % liczba_pierwsza == 0)
        {
            printf("%d ", liczba_pierwsza);
            N = N/liczba_pierwsza;
        }
        else
        {
            liczba_pierwsza++;
        }
    }
    
    return 0;
}