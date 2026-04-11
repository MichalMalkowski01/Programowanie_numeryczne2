#include <stdio.h>
#include <time.h>

/* Zadanie 1 */
double srednia(double tab[], int n) {
    if (n <= 0) return 0.0;

    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma += tab[i];
    }
    return suma / n;
}

/* Zadanie 2 */
unsigned long long silnia_iter(int n) {
    if (n < 0) return 0;

    unsigned long long wynik = 1;
    for (int i = 2; i <= n; i++) {
        wynik *= i;
    }
    return wynik;
}

unsigned long long silnia_rek(int n) {
    if (n < 0) return 0;
    if (n == 0 || n == 1) return 1;
    return n * silnia_rek(n - 1);
}

/* Zadanie 3 */
unsigned long long fib_iter(int n) {
    if (n < 0) return 0;
    if (n == 0) return 0;
    if (n == 1) return 1;

    unsigned long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

unsigned long long fib_rek(int n) {
    if (n < 0) return 0;
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib_rek(n - 1) + fib_rek(n - 2);
}

/* Zadanie 4 */
void odwroc_tablice(int tab[], int n) {
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = tab[i];
        tab[i] = tab[n - 1 - i];
        tab[n - 1 - i] = temp;
    }
}

/* Zadanie 5 */
void sklej(int *a, int *b, int a_size, int b_size, int *c) {
    int i = 0, j = 0, k = 0;

    while (i < a_size && j < b_size) {
        c[k++] = a[i++];
        c[k++] = b[j++];
    }

    while (i < a_size) {
        c[k++] = a[i++];
    }

    while (j < b_size) {
        c[k++] = b[j++];
    }
}

/* Funkcja pomocnicza do wypisywania tablicy */
void wypisz_tablice_int(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}
int main() {
    /* Zadanie 1 */
    double liczby[] = {2.5, 3.5, 4.0, 5.0};
    int n1 = sizeof(liczby) / sizeof(liczby[0]);
    printf("%d\n", n1);
    printf("Zadanie 1 - srednia: %.2f\n\n", srednia(liczby, n1));

    /* Zadanie 2 - porownanie wydajnosci */
    int n_silnia = 20;
    clock_t start, stop;

    start = clock();
    unsigned long long s1 = silnia_iter(n_silnia);
    stop = clock();
    double czas_iter_silnia = (double)(stop - start) / CLOCKS_PER_SEC;

    start = clock();
    unsigned long long s2 = silnia_rek(n_silnia);
    stop = clock();
    double czas_rek_silnia = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("Zadanie 2 - silnia(%d):\n", n_silnia);
    printf("Iteracyjnie: %llu, czas = %f s\n", s1, czas_iter_silnia);
    printf("Rekurencyjnie: %llu, czas = %f s\n\n", s2, czas_rek_silnia);

    /* Zadanie 3 - porownanie wydajnosci */
    int n_fib = 40;

    start = clock();
    unsigned long long f1 = fib_iter(n_fib);
    stop = clock();
    double czas_iter_fib = (double)(stop - start) / CLOCKS_PER_SEC;

    start = clock();
    unsigned long long f2 = fib_rek(n_fib);
    stop = clock();
    double czas_rek_fib = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("Zadanie 3 - fib(%d):\n", n_fib);
    printf("Iteracyjnie: %llu, czas = %f s\n", f1, czas_iter_fib);
    printf("Rekurencyjnie: %llu, czas = %f s\n\n", f2, czas_rek_fib);

    /* Zadanie 4 */
    int tab[] = {1, 2, 3, 4, 5, 6,7};
    int n2 = sizeof(tab) / sizeof(tab[0]);

    printf("Zadanie 4 - przed odwroceniem: ");
    wypisz_tablice_int(tab, n2);

    odwroc_tablice(tab, n2);

    printf("Zadanie 4 - po odwroceniu:    ");
    wypisz_tablice_int(tab, n2);
    printf("\n");

    /* Zadanie 5 */
    int a[] = {1, 3, 5, 7};
    int b[] = {2, 4, 6};
    int a_size = sizeof(a) / sizeof(a[0]);
    int b_size = sizeof(b) / sizeof(b[0]);
    int c[sizeof(a) / sizeof(a[0]) + sizeof(b) / sizeof(b[0])];

    sklej(a, b, a_size, b_size, c);

    printf("Zadanie 5 - sklejona tablica: ");
    wypisz_tablice_int(c, a_size + b_size);

    return 0;
}