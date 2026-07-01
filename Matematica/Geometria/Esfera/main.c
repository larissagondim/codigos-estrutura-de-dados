#include <stdio.h>
#include "calc_esfera.h"

int main(void) {
    float area, volume, r;
    printf("=== CALCULADORA DE ÁREA E VOLUME DE ESFERA ===\n");
    printf("\n\tInsira o raio da esfera: ");
    scanf("%f", &r);
    calc_esfera(r, &area, &volume);
    printf("\nÁrea = %.2f | Volume = %.2f\n", area, volume);
}
