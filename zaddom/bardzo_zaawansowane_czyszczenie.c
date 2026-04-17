#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double *bardzo_zaawansowane_czyszczenie(double tablica[], int N)
{
    double mean, three_sigma;
    int len = N;
    double temp[N];
    double *p = temp;

    for (int i = 0; i < N; i++)
    {
        *p = tablica[i];
        p++;
    }
    p = temp;

    do
    {
        N = len;

        mean = 0;
        for (int i = 0; i < N; i++)
        {
            mean += temp[i];
        }
        mean /= N;

        three_sigma = 0;
        for (int i = 0; i < N; i++)
        {
            three_sigma += pow(temp[i] - mean, 2);
        }
        three_sigma /= N;
        three_sigma = 3*sqrt(three_sigma);

        len = 0;
        for (int i = 0; i < N; i++)
        {
            if (temp[i] <= mean + three_sigma && temp[i] >= mean - three_sigma)
            {
                len++;
                *p = temp[i];
                p++;
            }
        }
        p = temp;
    } while(len != N);
    
    double *k = malloc(len * sizeof(double));
    for (int i = 0; i < len; i++)
    {
        *k = temp[i];
        k++;
    }
    k -= len;

    return k;
}

int main()
{
    double a[] = {50, 51, 49, 0, 49, 42.8, 50, 50, 50, 60, 50, 50, 50, 51, 50, 49.8, 50.1};
    double *p = bardzo_zaawansowane_czyszczenie(a, sizeof(a)/sizeof(a[0]));

    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        printf("%lf ", *p);
        p++;
    }

    return 0;
}