/* Nome do arquivo: pilha.c
 * Autoria: Larissa Gondim
 * Data: 08/06/2026
 * Descrição: implementação das funções de pilha
 * Versão: 1.0
 */

#include "pilha.h"

// corpo das funções

// 'cria_pilha'
Pilha *cria_pilha(void) {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    if(!pilha) return NULL;

    pilha->topo = -1;
    return pilha;
}

// 'libera_pilha'
void libera_pilha(Pilha **pilha) {
    if(pilha) {
        free(pilha);
        *pilha = NULL;
    }
}

// 'pilha_cheia'
int pilha_cheia(Pilha *pilha) {
    if(!pilha) return -1;
    return (pilha->topo == MAX-1);
}

// 'pilha_vazia'
int pilha_vazia(Pilha *pilha) {
    if(!pilha) return -1;
    return (pilha->topo == -1);
}

// 'push'
int push(Pilha *pilha, int elemento) {
    if(!pilha || pilha_cheia(pilha)) return 0;
    (pilha->topo)++;
    pilha->vetor[pilha->topo] = elemento;
    return 1;
}

// 'pop'
int pop(Pilha *pilha, int *elemento) {
    if(!pilha || pilha_vazia(pilha) || elemento == NULL) return 0;
    *elemento = pilha->vetor[(pilha->topo)];
    (pilha->topo)--;
    return 1;
}

// 'ver_topo'
int ver_topo(Pilha *pilha) {
    if(!pilha) return -1;
    return (pilha->vetor[pilha->topo]);
}


