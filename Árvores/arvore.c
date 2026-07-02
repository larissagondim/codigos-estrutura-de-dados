// Nome do arquivo: arvore.c
// Autoria: Larissa Vilasboas Gondim
// Descrição: implementação da estrutura de dados Árvore na linguagem C
// Data: 01/07/2026
// Versão: 1.0

// INCLUDES
#include "arvore.h"

// CORPO DE FUNÇÕES AUXILIARES

// 'cria'
void cria(tArvBin *T) {
    *T = NULL;
}

// 'vazia'
int vazia(tArvBin T) {
    return (T == NULL);
}

// 'busca'
tArvBin busca(tArvBin T, int dado) {
    tArvBin achou;

    if (T == NULL)
        return NULL; // árvore (ou sub-árvore) vazia

    if (T->conteudo == dado)
        return T; // elemento encontrado

    achou = busca(T->esq, dado);
    if (achou == NULL)
        achou = busca(T->dir, dado);

    return achou;
}

// 'insereRaiz'
int insereRaiz(tArvBin *T, int dado) {
    tNo *novoNo;

    if (*T != NULL)
        return 0; // árvore já possui raiz

    novoNo = malloc(sizeof(tNo));
    if (novoNo == NULL)
        return 0;

    novoNo->conteudo = dado;
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    *T = novoNo;
    return 1;
}

// 'insereDireita'
int insereDireita(tArvBin *T, int vPai, int vFilho) {
    tNo *f, *p, *novoNo;

    // verifica se o filho já não existe para evitar duplicata de dados
    f = busca(*T, vFilho);
    if (f != NULL)
        return 0; // dado já existe

    p = busca(*T, vPai);
    if (p == NULL)
        return 0; // pai não encontrado

    if (p->dir != NULL)
        return 0; // filho da direita já existe

    novoNo = malloc(sizeof(tNo));
    if (novoNo == NULL)
        return 0;

    novoNo->conteudo = vFilho;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    p->dir = novoNo;

    return 1;
}

// 'insereEsquerda'
int insereEsquerda(tArvBin *T, int vPai, int vFilho) {
    tNo *f, *p, *novoNo;

    // verifica se o filho já não existe para evitar duplicata de dados
    f = busca(*T, vFilho);
    if (f != NULL)
        return 0; // dado já existe

    p = busca(*T, vPai);
    if (p == NULL)
        return 0; // pai não encontrado

    if (p->esq != NULL)
        return 0; // filho da esquerda já existe

    novoNo = malloc(sizeof(tNo));
    if (novoNo == NULL)
        return 0;

    novoNo->conteudo = vFilho;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    p->esq = novoNo;

    return 1;
}

// 'preordem'
void preordem(tArvBin T) {
    if (T == NULL)
        return;

    printf("%d ", T->conteudo);

    if (T->esq != NULL)
        preordem(T->esq);
    if (T->dir != NULL)
        preordem(T->dir);
}

// 'posordem'
void posordem(tArvBin T) {
    if (T == NULL)
        return;

    if (T->esq != NULL)
        posordem(T->esq);
    if (T->dir != NULL)
        posordem(T->dir);

    printf("%d ", T->conteudo);
}