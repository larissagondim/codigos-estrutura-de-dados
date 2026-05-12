/* Nome do arquivo: pares.c
 * Autor: Larissa Gondim
 * Data: 11/05/2026
 * Descrição: Conta quantos são os pares num vetor
 * Versão: 1.0
 */
// includes padrão 
#include <stdio.h>
#include <stdlib.h>

// protótipos
/* @brief função que retorna quantos são os números pares armazenados no vetor
 * @param n: tamanho do vetor
 * @param *vet: ponteiro para o vetor
 * @return o número de valores pares no vetor
 * */
int pares(int n, int *vet);

/* @brief função que preenche vetor
 * @param n: tamanho do vetor
 * @param *vet: ponteiro para o vetor
 * @return nada pois é void
 * */
void preenche(int *vet, int n);

/* @brief função que verifica se a função foi alocada propriamente
 * @param *vet: ponteiro para o vetor
 * @return 0 se nao alocou, 1 se alocou
 * */
int alocou(int *vet);

// ---------- MAIN ----------
int main(void) {
    int n;
    scanf("%d", &n);

    int *p = malloc(n * sizeof(int));
    if (!alocou(p))
        exit(1);

    printf("\nPreencha o vetor: ");
    preenche(p, n);

    int n_pares = pares(n, p);
    printf("Número de pares: %d\n", n_pares);

    free(p);
    return 0;
}

int pares(int n, int *vet) {
    int i, n_pares = 0;
    for (i = 0; i < n; i++) {
        if (vet[i] % 2 == 0)
            n_pares++;
    }
    return n_pares;
}

void preenche(int *vet, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);  
    }
}

int alocou(int *vet) {
    if (vet == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        return 0;
    }
    return 1;
}