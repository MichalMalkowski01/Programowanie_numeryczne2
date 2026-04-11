#include <stdio.h>
#include <string.h>

/*
Zadanie 10.
Utwórz funkcję, która przyjmuje liczbę całkowitą dodatnią n
i zwraca sumę jej cyfr.
Przykład: dla 538 funkcja powinna zwrócić 16.
*/
int suma_cyfr(int n) {
    if (n < 0) n = -n;

    int suma = 0;
    while (n > 0) {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}

/*
Zadanie 11.
Utwórz funkcję, która przyjmuje napis (łańcuch znaków)
i sprawdza, czy jest palindromem.
Funkcja powinna zwracać 1, jeśli napis czytany od lewej i od prawej
jest taki sam, oraz 0 w przeciwnym przypadku.
*/
int czy_palindrom(char napis[]) {
    int lewy = 0;
    int prawy = strlen(napis) - 1;

    while (lewy < prawy) {
        if (napis[lewy] != napis[prawy]) {
            return 0;
        }
        lewy++;
        prawy--;
    }
    return 1;
}

/*
Zadanie 12.
Utwórz funkcję, która przyjmuje tablicę liczb całkowitych, jej rozmiar
oraz liczbę x, a następnie zwraca indeks pierwszego wystąpienia liczby x
w tablicy. Jeśli liczby nie ma w tablicy, funkcja powinna zwrócić -1.
*/
int znajdz_pierwszy(int tab[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (tab[i] == x) {
            return i;
        }
    }
    return -1;
}

/*
Zadanie 13.
Utwórz funkcję, która przyjmuje tablicę liczb całkowitych oraz jej rozmiar
i sprawdza, czy tablica jest rosnąca niemalejąco.
Funkcja powinna zwracać 1, jeśli dla każdego i zachodzi
tab[i] <= tab[i+1], oraz 0 w przeciwnym przypadku.
*/
int czy_niemalejaca(int tab[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (tab[i] > tab[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("Zadanie 10:\n");
    printf("Suma cyfr liczby 538 = %d\n\n", suma_cyfr(538));

    printf("Zadanie 11:\n");
    printf("Czy 'kajak' jest palindromem? %d\n", czy_palindrom("kajak"));
    printf("Czy 'dom' jest palindromem? %d\n\n", czy_palindrom("dom"));

    int tab[] = {4, 7, 2, 7, 9, 1};
    int n = sizeof(tab) / sizeof(tab[0]);

    printf("Zadanie 12:\n");
    printf("Pierwsze wystapienie 7 ma indeks %d\n", znajdz_pierwszy(tab, n, 7));
    printf("Pierwsze wystapienie 5 ma indeks %d\n\n", znajdz_pierwszy(tab, n, 5));

    int tab2[] = {1, 2, 2, 5, 8};
    int tab3[] = {1, 4, 3, 7};

    printf("Zadanie 13:\n");
    printf("Czy tab2 jest niemalejaca? %d\n", czy_niemalejaca(tab2, 5));
    printf("Czy tab3 jest niemalejaca? %d\n", czy_niemalejaca(tab3, 4));

    return 0;
}