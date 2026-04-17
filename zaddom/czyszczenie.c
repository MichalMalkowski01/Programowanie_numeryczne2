#include <stdio.h>
#include <stdlib.h>

double *czyszczenie(double tablica[], int N, double x)
{
    int len = 0;
    for (int i = 0; i < N; i++)
    {
        if (tablica[i] < x)
        {
            len++;
        }
    }

    double *p = malloc(len * sizeof(double));
    for (int i = 0; i < N; i++)
    {
        if (tablica[i] < x)
        {
            *p = tablica[i];
            p++;
        }
    }

    p -= len;

    return p;
}

int main()
{
    double a[10] = {4.5, 98.4, 34.5, 2.9, 60.2, 25.4, 83.5, 13.6, 54.6, 75.1};
    double *k = czyszczenie(a, 10, 50);

    for (int i = 0; i < 5; i++)
    {
        printf("%lf ", *k);
        k++;
    }

    return 0;
}