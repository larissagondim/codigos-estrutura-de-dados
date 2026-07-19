/* Nome do arquivo: somaAteN.c
 * Autoria: Larissa Gondim
 * Data: 19/07/2026
 * Descrição: função que implementa a soma de todos os números até N com recursividade
 * Versão: 1.0
 */

// INCLUDES 
// somente os padrão
#include <stdio.h>
#include <stdlib.h>

// 'somaAteN'
/// @brief função que calcula a soma de todos os números de 1 até n
/// @param n o valor limite que será calculado
/// @return o resultado da soma

int somaAteN(int n) {
    // caso base para evitar com que a função rode infinitamente
    if(n <= 1) return 1;
    
    // retorno com aplicação da recursividade
    else return (n + somaAteN(n-1));
}

// MAIN
// teste da função recém criada
int main(void) {
    int n, res;

    printf("\nInsira o valor limite (N) que deseja calcular a soma: ");
    scanf("%d", &n);

    res = somaAteN(n);

    printf("\nA soma de todos os números até '%d' é '%d'\n", n, res);

    return 0;
}