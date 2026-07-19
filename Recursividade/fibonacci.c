/* Nome do arquivo: fibonacci.c
 * Autoria: Larissa Gondim
 * Data: 19/07/2026
 * Descrição: função que implementa a sequência de fibonacci com recursividade
 * Versão: 1.0
 */

// INCLUDES 
// somente os padrão
#include <stdio.h>
#include <stdlib.h>

// 'fibonacci'
/// @brief função que calcula fibonacci
/// @param n o valor que será calculado
/// @return o resultado dos calculos

int fibonacci(int n) {
    // casos bases para evitar com que a função rode infinitamente
    if(n == 0) return 0;
    if(n == 1) return 1;

    // retorno com aplicação da recursividade
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// MAIN
// teste da função recém criada
int main(void) {
    int n, res;

    printf("\nInsira o valor que deseja calcular: ");
    scanf("%d", &n);

    res = fibonacci(n);

    printf("\nFibonacci de '%d' é '%d'", n, res);

    return 0;
}