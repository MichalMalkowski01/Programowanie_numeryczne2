#include <stdio.h>

int main() {
    char miesiac[20];
    char *p;

    scanf("%s", miesiac);
    p = miesiac;

    switch (*p) {
        case 's':
            if (*(p+1) == 't') printf("1\n");       // styczen
            else if (*(p+1) == 'i') printf("8\n");  // sierpien
            break;

        case 'l':
            if (*(p+1) == 'u') printf("2\n");       // luty
            else if (*(p+1) == 'i' && *(p+2) == 'p') printf("7\n");  // lipiec
            else printf("11\n"); // listopad
            break;

        case 'm':
            if (*(p+1) == 'a' && *(p+2) == 'r') printf("3\n"); // marzec
            else printf("5\n"); // maj
            break;

        case 'k':
            printf("4\n"); // kwiecien
            break;

        case 'c':
            printf("6\n"); // czerwiec
            break;

        case 'w':
            printf("9\n"); // wrzesien
            break;

        case 'p':
            printf("10\n"); // pazdziernik
            break;

        case 'g':
            printf("12\n"); // grudzien
            break;
    }

    return 0;
}