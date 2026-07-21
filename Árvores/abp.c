/* Nome do arquivo: abp.c
 * Autoria: Larissa Gondim
 * Data: 20/07/2026
 * Descrição: arquivo da implementação das funções de árvore binária de pesquisa
 * Versão: 1.0
 */

#include "abp.h"

// 'cria_arvore'
void cria_arvore(tAbp *T) {
    *T = NULL;
}

// 'eh_vazia'
int eh_vazia(tAbp T) {
    return (T == NULL);
}

// 'busca'
tAbp busca(tAbp T, int dado) {
    tAbp achou;
    if(T == NULL) return NULL;

    if(T->info == dado) return T; // encontrou na raiz

    if(T->info > dado) return busca(T->esq, dado);
    else return busca(T->dir, dado);
}

// 'exibe'
void exibe(tAbp T){
    if(T != NULL) {
        exibe(T->esq);
        printf("%d  ", T->info);
        exibe(T->dir);
    }
}

// 'insere'
int insere(tAbp *T, int item) {
    // verifica se o elemento já não está na árvore
    if(busca(*T, item) != NULL) return 0;

    // cria 3 novos nós:
    // novoNo -> nó que será inserido na árvore
    // atual -> intermediário pra percorrer a árvore
    // p -> salva posição no nó
    tNo *novoNo, *atual, *p;

    // cria novo nó e verifica alocação
    novoNo = malloc(sizeof(tNo));
    if(novoNo == NULL) return 0;

    // preenche novo nó
    novoNo->info = item;
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    // árvore vazia -> inserção na raiz
    if((*T) == NULL) { 
        (*T) = novoNo;
        return 1;
    }

    // atual se torna a árvore
    atual = (*T);

    // percorre a árvore atual até encontrar espaço vazio para inserção ordenada
    while(atual != NULL) {
        p = atual;
        if(item < atual->info) atual = atual->esq;
        else atual = atual->dir;
    }

    // esquerda caso seja menor que a informação contida no nó 
    // direita caso contrário
    if(item < p->info) p->esq = novoNo;
    else p->dir = novoNo;

    return 1;
}