#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double *zaawansowane_czyszczenie(double tablica[], int N)
{
    double mean = 0;
    for (int i = 0; i < N; i++)
    {
        mean += tablica[i];
    }
    mean /= N;
    printf("%lf\n", mean);

    double three_sigma = 0;
    for (int i = 0; i < N; i++)
    {
        three_sigma += pow(tablica[i] - mean, 2);
    }
    three_sigma /= N;
    three_sigma = 3*sqrt(three_sigma);
    printf("%lf\n", three_sigma);

    int len = 0;
    for (int i = 0; i < N; i++)
    {
        if (tablica[i] <= mean + three_sigma && tablica[i] >= mean - three_sigma)
        {
            len++;
        }
    }
    printf("%d\n", len);

    double *p = malloc(len * sizeof(double));
    for (int i = 0; i < N; i++)
    {
        if (tablica[i] <= mean + three_sigma && tablica[i] >= mean - three_sigma)
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
    double a[] = {50, 51, 49, 0, 48, 52, 50, 50, 50, 50, 50, 50, 50, 51, 50, 49.8, 50.1};
    double *k = zaawansowane_czyszczenie(a, sizeof(a)/sizeof(a[0]));

    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        printf("%lf ", *k);
        k++;
    }
    
    return 0;
}