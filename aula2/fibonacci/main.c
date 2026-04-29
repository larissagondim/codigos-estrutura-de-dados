#include <stdio.h>
#include "fibonacci.h"

int main(void) {
    int n, x;
    printf("Insira o n-ésimo índice que deseja acessar\n");
    scanf("%d", &n);
    x = fibonacci(n);
    printf("O n-ésimo termo da sequência de Fibonacci é: %d\n", x);
}