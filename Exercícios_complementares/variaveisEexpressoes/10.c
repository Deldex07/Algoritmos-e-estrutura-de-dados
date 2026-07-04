#include <stdio.h>

int main() {
    float km;
    scanf("%f", &km);
    float ms = km/3.6;
    printf("%.2f\n", ms);
    return 0;
}