#include <stdio.h>

int dozwolony_znak(char c) {
    if (c >= 'a' && c <= 'z') return 1;
    if (c >= 'A' && c <= 'Z') return 1;
    if (c >= '0' && c <= '9') return 1;
    if (c == '.' || c == '_' || c == '-') return 1;
    return 0;
}

int main() {
    char email[513];
    char *p;
    int liczba_malp = 0;
    char *pozycja_malpy = NULL;

    scanf("%s", email);

    p = email;
    while (*p != '\0') {
        if (*p == '@') {
            liczba_malp++;
            pozycja_malpy = p;
        } else if (!dozwolony_znak(*p)) {
            printf("NIE\n");
            return 0;
        }
        p++;
    }

    if (liczba_malp != 1) {
        printf("NIE\n");
        return 0;
    }

    if (pozycja_malpy == email || *(pozycja_malpy + 1) == '\0') {
        printf("NIE\n");
        return 0;
    }

    printf("TAK\n");

    return 0;
}