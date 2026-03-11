#include <stdio.h>

int main()
{
    char znak;
    scanf("%c", &znak);

    if (znak >= 'a' && znak <= 'z')
    {
        printf("TAK");
    }
    else
    {
        printf("NIE");
    }

    return 0;
}