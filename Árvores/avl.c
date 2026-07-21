/* Nome do arquivo: avl.c
 * Autoria: Larissa Gondim
 * Data: 21/07/2026
 * Descrição: arquivo da implementação das funções de árvore AVL
 * Versão: 1.0
 */

#include "avl.h"

// 'cria'
void cria(tAVL *T) {
    // inicializa a raiz da árvore como vazia (nula)
    *T = NULL;
}

// 'eh_vazia'
int eh_vazia(tAVL T) {
    // retorna verdadeiro (1) se a árvore for nula e falso (0) caso contrário
    return (T == NULL);
}

// 'exibe'
void exibe(tAVL T) {

    // se a árvore estiver vazia, encerra a execução
    if(T == NULL) return;

    // visita a subárvore esquerda (impressão em ordem - in-order)
    if(T->esq != NULL) exibe(T->esq);

    // imprime o dado do nó atual
    printf("%d  ", T->dado);

    // visita a subárvore direita
    if(T->dir != NULL) exibe(T->dir);

}

// 'busca'
tAVL busca(tAVL T, int info) {

    // se chegou num nó nulo, a informação não está na árvore
    if(T == NULL) return NULL;

    // encontrou a informação no nó atual
    if(T->dado == info) return T;

    // se a informação buscada for menor que o dado atual, continua a busca pela subárvore esquerda
    if(info < T->dado) return busca(T->esq, info);

    // caso contrário (maior), continua a busca pela subárvore direita
    else return busca(T->dir, info);

}

// 'insere'
int insere(tAVL *T, int item) {
    // variável de controle para identificar se a altura da árvore mudou
    int ok;

    // inserção na raíz ou alcançou o local correto de inserção (nó folha)
    if(*T == NULL) {
        // aloca espaço na memória para o novo nó
        *T = malloc(sizeof(tNo));
        if((*T) == NULL) return 0; // verifica falha na alocação
        
        // preenche os dados do novo nó recém-criado
        (*T)->dado = item;
        (*T)->fb = 0; // todo novo nó folha possui Fator de Balanceamento (FB) igual a 0
        (*T)->esq = NULL;
        (*T)->dir = NULL;
        return 1; // retorna 1 indicando que a altura deste ramo cresceu
    }

    // se o item for menor que a raiz atual, desce para a subárvore esquerda
    if((*T)->dado > item) {
        ok = insere(&(*T)->esq, item);

        // se a inserção ocorreu e propagou mudança de altura
        if(ok != 0) {
            // checa o Fator de Balanceamento (FB) atual para decidir a propagação
            switch((*T)->fb) {
                case 1:
                    ok = 0; // a altura da árvore compensou, não cresceu mais
                    break;
                case 0:
                    break; // repassa a propagação do aumento de altura para cima
                case -1:
                    ok = 0; // árvore desbalanceada (neste ponto do código original deveriam ocorrer as rotações)
                    break;
            }
        }
    }

    // se o item for maior que a raiz atual, desce para a subárvore direita
    else if((*T)->dado < item) {
        ok = insere(&((*T)->dir), item);

        // se a inserção ocorreu e propagou mudança de altura
        if(ok) {
            // checa o Fator de Balanceamento (FB) atual para decidir a propagação
            switch((*T)->fb) {
                case -1:
                    ok = 0; // a altura da árvore compensou, não cresceu mais
                    break;
                case 0:
                    break; // repassa a propagação do aumento de altura para cima
                case 1:
                    ok = 0; // árvore desbalanceada (neste ponto do código original deveriam ocorrer as rotações)
                    break;
            }
        }
    }
    // se o item for igual ao dado do nó atual (elemento já existe, AVL não aceita duplicatas)
    else {
        ok = 0;
        return ok; // inserção falha
    }
}

// 'rotacao_direita'
void rotacao_direita(tAVL *T) {
    // salva o filho à esquerda do nó desbalanceado em um ponteiro auxiliar temporário (nT)
    tAVL nT = (*T)->esq;
    
    // o filho à direita do nó auxiliar passa a ser o filho à esquerda do nó desbalanceado
    (*T)->esq = nT->dir;
    
    // o nó desbalanceado desce e se torna o filho à direita do nó auxiliar
    nT->dir = *T;
    
    // a raiz principal da subárvore passa a apontar para o nó auxiliar (nova raiz balanceada)
    *T = nT;
}