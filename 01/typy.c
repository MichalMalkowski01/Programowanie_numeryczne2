#include <stdio.h>

int main() {
    int a = 5; // Zmienna typu całkowitego
    double b = 3.14; // Zmienna typu zmiennoprzecinkowego
    char c = 'A'; // Zmienna typu znakowego
    float d = 2.5f; // Zmienna typu zmiennoprzecinkowego pojedynczej precyzji

    printf("Wartość a: %d\n", a);
    printf("Wartość b: %.2lf\n", b);
    printf("Wartość c: %c\n", c);
    printf("Wartość d: %.2f\n", d);

    return 0;
}