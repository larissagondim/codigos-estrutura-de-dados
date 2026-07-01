/* Nome do arquivo: fila_encadeada.c
 * Autoria: Larissa Gondim
 * Data: 17/06/2026
 * Descrição: implementação das funções da fila com lista encadeada
 * Versão: 1.0
 */

#include "fila_encadeada.h"

Fila* cria_fila(void) {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if (f == NULL) {
        printf("Erro: memória insuficiente!\n");
        return NULL;
    }
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
    return f;
}

void libera_fila(Fila** fila) {
    if (fila == NULL || *fila == NULL) 
        return;

    No* atual = (*fila)->inicio;
    while (atual != NULL) {
        No* prox = atual->prox;
        free(atual);
        atual = prox;
    }
    
    free(*fila);
    *fila = NULL;
}

int fila_vazia(Fila* fila) {
    if (fila == NULL) 
        return 1;  
    return (fila->inicio == NULL);
}

int enfileirar(Fila* fila, int elemento) {
    if (fila == NULL) {
        printf("Erro: fila não existe!\n");
        return 0;
    }

    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: memória insuficiente!\n");
        return 0;
    }
    
    novo->dado = elemento;
    novo->prox = NULL;
    
    if (fila_vazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
    
    fila->tamanho++;
    return 1;
}

int desenfileirar(Fila* fila, int* elemento) {
    if (fila == NULL || fila_vazia(fila)) {
        printf("Erro: fila vazia!\n");
        return 0;
    }
    
    No* removido = fila->inicio;
    *elemento = removido->dado;
    
    fila->inicio = removido->prox;

    if (fila->inicio == NULL) 
        fila->fim = NULL;

    free(removido);
    fila->tamanho--;
    
    return 1;
}

int ver_frente(Fila* fila) {
    if (fila == NULL || fila_vazia(fila)) {
        printf("Erro: fila vazia!\n");
        return -1;  
    }
    return fila->inicio->dado;
}

int tamanho_fila(Fila* fila) {
    if (fila == NULL) 
        return 0;
    return fila->tamanho;
}