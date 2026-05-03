#include <stdio.h>
#include "soma_impares.h"

int main(void) {
    int n;
    printf("Insira o número que deseja ser o valor limítrofe do somatório: ");
    scanf("%d", &n);
    int x = soma_impares(n);
    printf("\nO valor do somatório de todos os valores inteiros até '%d' é: '%d'", n, x);
    return 0;
}
