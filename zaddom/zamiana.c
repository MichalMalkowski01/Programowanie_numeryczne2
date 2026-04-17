#include <stdio.h>

int main()
{
    char wyraz[100];
    scanf("%s", wyraz);
    
    char *p = wyraz;

    while(*p != '\0')
    {
        if (*p >= 'a' && *p <= 'z')
        {
            *p -= 32;
        }
        else if (*p >= 'A' && *p <= 'Z')
        {
            *p += 32;
        }

        p++;
    }

    printf("%s\n", wyraz);

    return 0;
}