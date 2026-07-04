#include <stdio.h>

int main() {
    float Kelvin;
    scanf("%f", &Kelvin);
    float celcius = Kelvin - 273.15;
    printf("%.2f\n", celcius);
}