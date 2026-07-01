/* Nome do arquivo: negativos.c                                                                                                                                                                                                                   * Nome do arquivo: vetor.c
 * Autor: Larissa Gondim
 * Data: 11/05/2026
 * Descrição: Conta quantos são os negativos num vetor
 * Versão: 1.0
 */

// includes
#include <stdio.h>
#include <stdlib.h>

// funções auxiliares
/* @brief função que retorna quantos são os números negativos armazenados no vetor
 * @param n: tamanho do vetor
 * @param *vet: ponteiro para o vetor
 * @return o número de valores negativos no vetor
 * */
int negativos(int n, float *vet);

/* @brief função que preenche vetor
 * @param n: tamanho do vetor
 * @param *vet: ponteiro para o vetor
 * @return nada pois é void
 * */
void preenche(float *vet, int n);

/* @brief função que verifica se a alocação foi efetivsa
 * @param *vet: ponteiro para o vetor
 * @return 0 se não alocou, 1 caso contrário
 * */
int alocou(float *vet);

// ---------- MAIN ----------
int main(void) {
    int n;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);

    float *p = malloc(n * sizeof(float));
    if (!alocou(p))
        exit(1);
    printf("\nPreencha o vetor: ");
    preenche(p, n);

    int n_neg = negativos(n, p);
    printf("Número de negativos: %d\n", n_neg);

    free(p);
    return 0;
}

int alocou(float *vet) {
    if (vet == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        return 0;
    }
    return 1;
}

int negativos(int n, float *vet) {
    int i, n_negativos = 0;
    for(i = 0; i < n; i++) {
        if(!(vet[i] >= 0)) 
            n_negativos += 1;
    }
    return n_negativos;
}

void preenche(float *vet, int n) {
    for(int i = 0; i < n; i++) {
        scanf("%f", &vet[i]);
    }
}

