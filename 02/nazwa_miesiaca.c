#include <stdio.h>

int main()
{
    int miesiac;
    scanf("%d", &miesiac);

    switch (miesiac)
    {
        case 1:
            printf("styczen");
            break;
        case 2:
            printf("luty");
            break;
        case 3:
            printf("marzec");
            break;
        case 4:
            printf("kwiecien");
            break;
        case 5:
            printf("maj");
            break;
        case 6:
            printf("czerwiec");
            break;
        case 7:
            printf("lipiec");
            break;
        case 8:
            printf("sierpien");
            break;
        case 9:
            printf("wrzesien");
            break;
        case 10:
            printf("pazdziernik");
            break;
        case 11:
            printf("listopad");
            break;
        case 12:
            printf("grudzien");
            break;
        default:
            printf("niewlasciwe dane");
    }

    return 0;
}