/* Nome do arquivo: fila.c
 * Autoria: Larissa Gondim
 * Data: 15/06/2026
 * Descrição: implementação das funções da fila estática circular
 * Versão: 1.0
 */

#include "fila.h"

// cria_fila
Fila *cria_fila(void) {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if (f == NULL)
        return NULL;
    f->inicio = 0;
    f->fim = 0;
    return f;
}

// libera_fila
void libera_fila(Fila **fila) {
    if (fila == NULL || *fila == NULL)
        return;
    free(*fila);
    *fila = NULL;
}

// fila_cheia
int fila_cheia(Fila *fila) {
    if (fila == NULL)
        return 1;
    return ((fila->fim + 1) % MAX == fila->inicio);
}

// fila_vazia
int fila_vazia(Fila *fila) {
    if (fila == NULL)
        return 1;
    return (fila->inicio == fila->fim);
}

// enfileirar
int enfileirar(Fila *fila, int elemento) {
    if (fila == NULL || fila_cheia(fila))
        return 0;
    
    fila->vetor[fila->fim] = elemento;
    fila->fim = (fila->fim + 1) % MAX;
    return 1;
}

// desenfileirar
int desenfileirar(Fila *fila, int *elemento) {
    if (fila == NULL || fila_vazia(fila) || elemento == NULL)
        return 0;
    
    *elemento = fila->vetor[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX;
    return 1;
}

// ver_frente
int ver_frente(Fila *fila) {
    if (fila == NULL || fila_vazia(fila))
        return -1;
    return fila->vetor[fila->inicio];
}

// tamanho_fila
int tamanho_fila(Fila *fila) {
    if (fila == NULL || fila_vazia(fila))
        return 0;
    
    if (fila->fim >= fila->inicio)
        return fila->fim - fila->inicio;
    else
        return (MAX - fila->inicio) + fila->fim;
}