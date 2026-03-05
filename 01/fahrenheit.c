#include <stdio.h>
int main(){

    double fahrenheit, celsius;
    printf("Podaj temperaturę w stopniach Fahrenheita: ");
    scanf("%lf", &fahrenheit);
    celsius = (fahrenheit - 32) * 5.0 / 9.0;
    printf("%.2lf stopni Fahrenheita to %.2lf stopni Celsjusza.\n", fahrenheit, celsius);

    return 0;
}