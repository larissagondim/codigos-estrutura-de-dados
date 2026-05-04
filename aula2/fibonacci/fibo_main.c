/*
 * Nome do arquivo: fibo_main.c
 * Autor: Seu Nome
 * Data: 29/04/2026
 * Descrição: Programa que calcula o n-ésimo termo de Fibonacci
 * Versão: 1.0
 */

#include <stdio.h>
// protótipo de funções:
int fibo(int);
// ----------- MAIN -----------
int main(void){
   int n, n_esimo;
   printf("Insira o tamanho da sequência de fibonacci que você deseja acessar os termos: ");
   scanf("%d", &n);
   n_esimo = fibo(n);
   printf("\nO n-ésimo termo da sequência de fibonacci de '%d' termos é: '%d'", n, n_esimo);
   return 0;
}
/**@brief função que retorna o n-ésimo termo da sequência de fibonacci (considerando F(1) = 1 e F(2) = 2)
 **@param n posição 'n' na qual o termo da sequência está localizado
 **@return o n-ésimo termo da sequência de fibonacci ou 0 para entradas inválidas
 */
int fibo(int n) {
    if(n <= 0) 
        return 0;
    if(n == 1 || n == 2) 
	return 1;

    /* 'a' e 'b' armazenam os dois últimos termos da sequência (considerando a posição atual)
     *'proximo': representa o próximo termo da sequência de fibonacci (dado pela soma dos 2 anteriores)
    */
    int a = 1, b = 1, proximo, i;

    for(i = 3; i <= n; i++) {
        proximo = a + b;
        a = b;
	b = proximo;
    }

    return b;
}
