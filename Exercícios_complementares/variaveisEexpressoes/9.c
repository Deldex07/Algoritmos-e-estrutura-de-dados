#include <stdio.h>

int main() {
    float celcius;
    scanf("%f", &celcius);
    float Kelvin = celcius + 273.15;
    printf("%.2f\n", Kelvin);
}