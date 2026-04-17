#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    double position[N];
    double *p = position;
    for (int i = 0; i < N; i++)
    {
        scanf("%lf", p);
        p++;
    }

    int direction[N];
    int *q = direction;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", q);
        if (*q == 0)
        {
            *q = -1;
        }
        q++;
    }

    // Analitycznie

    double max_time = 0;
    p = position;
    q = direction;
    for (int i = 0; i < N; i++)
    {
        if (*q == 1)
        {
            if (100 - *p > max_time)
            {
                max_time = 100 - *p;
            }
        }
        else
        {
            if (*p > max_time)
            {
                max_time = *p;
            }
        }
        p++;
        q++;
    }

    printf("Analitycznie: %lf\n", max_time);

    // Numerycznie

    double time = 0;
    int mrowki = N;

    while(mrowki > 0)
    {
        p = position;
        q = direction;
        mrowki = 0;
        for (int i = 0; i < N; i++)
        {
            *p += *q*0.001;
            if (*p > 0 && *p < 100)
            {
                mrowki++;
            }
            p++;
            q++;
        }

        p = position;
        q = direction;
        for (int i = 0; i < N - 1; i++)
        {
            if (*p >= *(p+1))
            {
                int temp = *q;
                *q = *(q+1);
                *(q+1) = temp;
            }
            p++;
            q++;
        }

        time += 0.001;
    }

    printf("Numerycznie: %lf\n", time);

    return 0;
}