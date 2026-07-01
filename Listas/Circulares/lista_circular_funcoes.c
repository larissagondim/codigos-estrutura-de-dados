/* Nome do arquivo: lista_circular_funcoes.c
 * Autoria: Larissa Gondim
 * Data: 17/05/2026
 * Descrição: implementação das funções da lista circular
 * Versão: 1.0
 */

#include "lista_circular.h"

// corpo de funções auxiliares

void esvazia_lista(lc *lista) {
    lista->ctri = -1;
    lista->ctrf = -1;
}

void imprimir(lc *lista) {
    if (lista_vazia(lista)) {
        printf("\nLista vazia!");
        return;
    }

    int i = lista->ctri;

    while (1) {
        printf("%d ", lista->v[i]);
        if (i == lista->ctrf)
            break;
        i = (i + 1) % TAM;
    }

    printf("\n");
}

void insercao_no_inicio(lc *lista, int num) {
    // verifica se está cheia
    if (lista_cheia(lista)) {
        printf("\nLista cheia!");
        return;
    }

    // primeira inserção
    if (lista_vazia(lista)) {
        lista->ctri = 0;
        lista->ctrf = 0;
    }
    else 
        lista->ctri = (lista->ctri - 1 + TAM) % TAM;

    lista->v[lista->ctri] = num;
}

void insercao_no_final(lc *lista, int num) {
    // verifica se está cheia
    if (lista_cheia(lista)) {
        printf("\nLista cheia!");
        return;
    }

    // primeira inserção
    if (lista_vazia(lista)) {
        lista->ctri = 0;
        lista->ctrf = 0;
    }
    else // avança circularmente o final
        lista->ctrf = (lista->ctrf + 1) % TAM;

    lista->v[lista->ctrf] = num;
}

void insercao_no_meio(lc *lista, int pos, int num) {
    // verifica lista cheia
    if (lista_cheia(lista)) {
        printf("\nLista cheia!");
        return;
    }

    // lista vazia
    if (lista_vazia(lista)) {
        lista->ctri = 0;
        lista->ctrf = 0;
        lista->v[0] = num;
        return;
    }

    // calcula tamanho atual
    int tamanho = (lista->ctrf - lista->ctri + TAM) % TAM + 1;

    // posição inválida
    if (pos < 0 || pos > tamanho) {
        printf("\nPosição inválida!");
        return;
    }

    // inserção no final
    if (pos == tamanho) {
        insercao_no_final(lista, num);
        return;
    }

    // avança o final
    lista->ctrf = (lista->ctrf + 1) % TAM;

    // desloca elementos para direita
    for (int i = tamanho; i > pos; i--) {
        int atual = (lista->ctri + i) % TAM;
        int anterior = (lista->ctri + i - 1) % TAM;

        lista->v[atual] = lista->v[anterior];
    }

    // insere novo elemento
    int indice = (lista->ctri + pos) % TAM;
    lista->v[indice] = num;
}

int lista_vazia(lc *lista) {
    return (lista->ctri == -1);
}

int lista_cheia(lc *lista) {
    return ((lista->ctrf + 1) % TAM == lista->ctri);
}