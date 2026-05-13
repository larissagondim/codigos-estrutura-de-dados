/* Nome do arquivo: inverter.c
 * Autoria: Larissa Gondim
 * Data: 12/05/2026
 * Descrição: código que recebe um vetor de números inteiros e inverte a ordem dos seus elementos
 * Versão: 1.1
 * */

// includes (apenas as bibliotecas padrão)
#include <stdio.h>
#include <stdlib.h>

/* 'alocou'
 * @brief função que veriifica se a alocação dinâmica ocorreu de maneira efetiva
 * @param *vet conteúdo do ponteiro que aponta pro vetor
 * @return 1 se alocou propriamente, 0 caso contrário
 * */
int alocou(int *vet);

// protótipo das funções auxiliares
/* 'inverte'
 * @brief função que recebe um vetor de números inteiros e inverte a ordem de seus elementos
 * @param *vet conteudo do ponteiro que aponta para o vetor
 * @param n tamanho do vetor
 * @return nada pois é void
 * */
void inverte(int n, int *vet);

/* 'mostra'
 * @brief função que mostra o vetor digitado
 * @param *vet conteúdo do ponteiro que aponta pro vetor
 * @param n tamanho do vetor
 * @return nada pois é void
 * */
void mostra(int n, int *vet);

/* 'preenche'
 * @brief função que preenche o vetor dinamicamente alocado
 * @param *vet conteúdo do ponteiro que aponta pro vetor
 * @param n tamanho do vetor
 * @return nada pois é void
 * */
void preenche(int n, int *vet);

// ---------- MAIN ----------
int main(void) {
    int n;
    printf("Insira o tamanho do vetor em análise: ");
    scanf("%d", &n);
    while(n < 0) {
        printf("Insira um tamanho válido (positivo): ");
        scanf("%d", &n);
    }
    int *p = (int *) malloc(n * sizeof(int));

    // verificando se a alocação foi efetiva
    if(!(alocou(p))) 
        exit(1);

    // preenchendo o vetor
    preenche(n, p);
    
    // moostrando um vetor antes
    printf("\nVetor antes da inversão: ");
    mostra(n, p);

    // invertendo os valores
    inverte(n, p);

    // mostrando o vetor após a inversão
    printf("\nVetor após a inversão: ");
    mostra(n, p);

    // liberando o espaço na memória
    free(p);
    return 0;
}

int alocou(int *vet) {
    if(vet == NULL) 
	   return 0;
    return 1;
}

// corpo das funções auxiliares
void inverte(int n, int *vet) {
    int i, temp = 0;
    for(i = 0; i < n/2; i++) {
        temp = vet[n - i - 1];
        vet[n - i - 1] = vet[i];
        vet[i] = temp;
    }
}

void mostra(int n, int *vet) {
    int i;
    printf("\n{");
    if(n> 0) {
        for(i = 0; i < n-1; i++) {
            printf("%d, ", vet[i]);
        }
        printf("%d}", vet[i]);
    }
} 

void preenche(int n, int *vet) {
    int i;
    for(i = 0; i < n; i++) {
        printf("\nInsira o dígito de número '%d': ", (i+1));
        scanf("%d", &vet[i]);
    }
}
