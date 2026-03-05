#include <stdio.h>

int main(){

    double ml, km;
    printf("Podaj odległość w milach: ");
    scanf("%lf", &ml);

    km = ml * 1.609344;

    printf("%.2lf mil to %.2lf kilometrów.\n", ml, km);

    return 0;
}