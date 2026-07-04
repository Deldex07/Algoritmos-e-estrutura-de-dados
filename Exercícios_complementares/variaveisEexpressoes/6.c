#include <stdio.h>

int main() {
    float celcius;
    scanf("%f", &celcius);
    float fahrenheit = (celcius *9.0/5.0) + 32.0;
    printf("%.2f\n", fahrenheit);
}