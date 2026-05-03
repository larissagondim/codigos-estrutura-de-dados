#include <stdio.h>
#include "raizes.h"

int main(void) {
    float x1, x2, a = 1, b = -5, c = 6;
    printf("=== ENCONTRE SUA RAÍZ DA EQUAÇÃO DE SEGUNDO GRAU ===\n");
    printf("\n\tInsira o coeficiente 'a' da equação: ");
    scanf("%f", &a);
    printf("\tInsira o coeficiente 'b' da equação: ");
    scanf("%f", &b);
    printf("\tInsira a constante 'c' da equação: ");
    scanf("%f", &c);
    raizes(a, b, c, &x1, &x2);
    printf("\n=> As raízes reais da equação são: '%.2f' e '%.2f'\n", x1, x2);
    return 0;
}
