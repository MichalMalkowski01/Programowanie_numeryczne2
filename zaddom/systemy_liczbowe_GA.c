#include <stdio.h>

int main()
{
    int a, b, i;
    scanf("%d %d", &a, &b);

    int wynik = 0;
    // deklaruj i tylko w forze, a nie przed pętlą, bo i jest potrzebne tylko w tej pętli
    for (i = 1; a > 0;)
    {
        wynik = wynik + (a % b)*i;
        a = a / b;
        i = i*10;
    }
    printf("%d", wynik);

    return 0;
}