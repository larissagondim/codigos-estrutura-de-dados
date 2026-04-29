#include <stdio.h>
#include "dentro_ret.h"
int main(void) {
    int a1, b1, a0, b0, a, b;
    printf("Insira as coordenadas do ponto desejado: \n");
    scanf("%d %d", &a, &b);
    printf("Insira as coordenadas do vértice superior esquerdo: \n");
    scanf("%d %d", &a0, &b0);
    printf("Insira as coordenadas do vértice superior direito: \n");
    scanf("%d %d", &a1, &b1);
    printf("O ponto está ");
    printf("%s", dentro_ret(a0, b0, a1, b1, a, b) ? "dentro" : "fora");
    puts(" do retângulo");

    return 0;
}