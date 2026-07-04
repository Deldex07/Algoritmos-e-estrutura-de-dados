#include <stdio.h>

int main() {
    float fahrenheit;
    scanf("%f", &fahrenheit);
    float celcius = 5.0*(fahrenheit - 32.0)/9.0;
    printf("%.2f\n", celcius);
}