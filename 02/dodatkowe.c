/*
Zadanie dodatkowe.

Napisz program kalendarz.c, który wczyta ze standardowego wejścia dwie liczby całkowite:
rok oraz numer miesiąca.

Program ma wypisać na standardowe wyjście:
1. polską nazwę miesiąca,
2. liczbę dni w tym miesiącu,
3. numer kwartału, do którego należy ten miesiąc.

Uwzględnij lata przestępne, zakładając, że są to lata:
- podzielne przez 4 i niepodzielne przez 100 lub
- podzielne przez 400.

Jeżeli numer miesiąca jest niepoprawny, wypisz komunikat:
BLEDNE DANE

Przykład:
Dla danych wejściowych:
2024 2

program powinien wypisać:
luty
29 dni
1 kwartal

Wskazówki:
- użyj tablicy do przechowywania liczby dni w miesiącach,
- użyj tablicy do przechowywania nazw miesięcy,
- użyj instrukcji switch albo obliczenia arytmetycznego do wyznaczenia kwartału.
*/

#include <stdio.h>

int main() {
    int rok, miesiac;

    char *nazwy[12] = {
        "styczen", "luty", "marzec", "kwiecien",
        "maj", "czerwiec", "lipiec", "sierpien",
        "wrzesien", "pazdziernik", "listopad", "grudzien"
    };

    int dni_w_miesiacach[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    scanf("%d %d", &rok, &miesiac);

    if (miesiac < 1 || miesiac > 12) {
        printf("BLEDNE DANE\n");
        return 0;
    }

    int rok_przestepny = 0;
    if ((rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0)) {
        rok_przestepny = 1;
    }

    int liczba_dni = dni_w_miesiacach[miesiac - 1];
    if (miesiac == 2 && rok_przestepny) {
        liczba_dni = 29;
    }

    int kwartal;
    switch (miesiac) {
        case 1:
        case 2:
        case 3:
            kwartal = 1;
            break;
        case 4:
        case 5:
        case 6:
            kwartal = 2;
            break;
        case 7:
        case 8:
        case 9:
            kwartal = 3;
            break;
        case 10:
        case 11:
        case 12:
            kwartal = 4;
            break;
    }

    printf("%s\n", nazwy[miesiac - 1]);
    printf("%d dni\n", liczba_dni);
    printf("%d kwartal\n", kwartal);

    return 0;
}