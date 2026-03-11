#include <stdio.h>

int main()
{
    int rok, miesiac;
    scanf("%d %d", &rok, &miesiac);

    int dni;

    switch (miesiac)
    {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            dni = 31;
            break;
        case 4: case 6: case 9: case 11:
            dni = 30;
            break;
        case 2:
            // Sprawdzamy czy rok przestępny
            if ((rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0))
                dni = 29;
            else
                dni = 28;
            break;
        default:
            dni = -1; // nieprawidłowy miesiąc
    }

    if (dni == -1)
        printf("niewlasciwe dane\n");
    else
        printf("%d\n", dni);

    return 0;
}