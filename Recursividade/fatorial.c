/* Nome do arquivo: fatorial.c
 * Autoria: Larissa Gondim
 * Data: 19/07/2026
 * Descrição: função que implementa o cálculo de fatorial com recursividade
 * Versão: 1.0
 */

#include <stdio.h>
#include <stdlib.h>

// 'fatorial'
/// @brief função que calcula fatorial de um número n
/// @param n o valor que será calculado
/// @return o resultado dos calculos

int fatorial(int n) {
    // caso base para evitar com que a função rode infinitamente
    if(n <= 1) return 1;

    // retorno com aplicação da recursividade
    else return (n * fatorial(n - 1));
}

// MAIN
// teste da função recém criada
int main(void) {
    int n, res;

    printf("\nInsira o valor que deseja calcular: ");
    scanf("%d", &n);
    
    res = fatorial(n);

    printf("\n%d! = %d", n, res);
    return 0;
}