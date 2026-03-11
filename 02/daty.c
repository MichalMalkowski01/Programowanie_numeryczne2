#include <stdio.h>

// Liczba dni w miesiącach dla roku nieprzestępnego
int dni_w_miesiacu[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int rok1, mies1, dzien1;
    int rok2, mies2, dzien2;

    // Wczytanie dwóch dat
    scanf("%d %d %d", &rok1, &mies1, &dzien1);
    scanf("%d %d %d", &rok2, &mies2, &dzien2);

    // Zamiana każdej daty na liczbę dni od początku roku 0 (bez lat przestępnych)
    int dni1 = dzien1;
    for (int i = 0; i < mies1 - 1; i++)
        dni1 += dni_w_miesiacu[i];
    dni1 += rok1 * 365;

    int dni2 = dzien2;
    for (int i = 0; i < mies2 - 1; i++)
        dni2 += dni_w_miesiacu[i];
    dni2 += rok2 * 365;

    int roznica = dni2 - dni1;
    printf("%d dni\n", roznica);

    return 0;
}