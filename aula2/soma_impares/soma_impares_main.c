/*
 * Nome do arquivo: soma_impares_main.c
 * Autoria: Larissa Gondim
 * Data: 29/04/2026
 * Descrição: Programa que soma todos os ímpares num intervalo de 1 a 'n'
 * Versão: 1.0
 */
#include <stdio.h>

// protótipo de função:
void soma_impares(int, int *);

// -------- MAIN --------
int main(void) {
    int n, s;
    printf("Insira o valor limítrofe do seu intervalo: ");
    scanf("%d", &n);
    soma_impares(n, &s);
    return 0;
}
// -------- FUNÇÃO SOMA_IMPARES (passagem por referência) --------
// @brief função responsável por somar todos os inteiros positivos de 1 até 'n'
// @param n valor limítrofe do intervalo
// @param *s ponteiro que aponta pra variável que armazenará o resultado do somatório
// @return a função é void, ou seja, sem retorno, apenas imprime
void soma_impares(int n, int *s) {
    printf("A soma de todos os inteiros positivos no intervalo [1, %d] resulta em ", n);
    *s = 0;
    int i = 0;
    for(int i = 1; i <= n; i++) 
	*s += i;
    printf("'%d'\n", *s);
}
