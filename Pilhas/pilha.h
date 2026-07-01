/* Nome do arquivo: pilha.h
 * Autoria: Larissa Gondim
 * Data: 08/06/2026
 * Descrição: arquivo de cabeçalho da implementação de pilha
 * Versão: 1.0
 */

#ifndef PILHA_H
#define PILHA_H

// MACROS
// MAX: define tamanho da pilha
#define MAX 50

// INCLUDES
// apenas os padrão
#include <stdio.h>
#include <stdlib.h>

// ESTRUTURAS

// 'pilha'
// representa a estrutura comum de pilha que será utilizada nas implementações
// topo: elemento localizado no topo da pilha
// vetor[MAX]: elementos da pilha

struct pilha {
    int topo;
    int vetor[MAX];
}; 
// 'Pilha' é um alias para a struct pilha
typedef struct pilha Pilha;

// protótipo de funções auxiliares

// 'cria_pilha'
//// @brief cria e inicializa uma pilha vazia
//// @param nada 
//// @return a pilha recém criada
Pilha *cria_pilha(void);

// 'libera_pilha'
//// @brief libera a memória que foi alocada para a pilha
//// @param **pilha: ponteiro para a pilha que será deletada
//// @return nada pois é void
void libera_pilha(Pilha **pilha);

// 'pilha_cheia'
//// @brief verifica se a pilha está cheia
//// @param *pilha: ponteiro para a pilha em análise
//// @return retorna 1 caso esteja cheia e 0 caso esteja vazia
int pilha_cheia(Pilha *pilha);

// 'pilha_vazia'
//// @brief verifica se a pilha ta vazia
//// @param *pilha: ponteiro para a pilha em análise
//// @return retorna 1 caso esteja vazia e 0 caso contrário
int pilha_vazia(Pilha *pilha);

// 'push'
//// @brief função que insere elemento no topo da pilha
//// @param *pilha: ponteiro para a pilha
//// @param elemento: elemento que será adicionado na pilha
//// @return 0 caso a pilha esteja cheia e 1 caso contrário (ou seja, elemento adicionado)
int push(Pilha *pilha, int elemento);

// 'pop'
//// @brief função que remove elemento no topo da pilha
//// @param *pilha: ponteiro para a pilha
//// @param *elemento: ponteiro para guardar o elemento removido
//// @return 0 caso a pilha esteja vazia e 1 caso contrário
int pop(Pilha *pilha, int *elemento);

// 'ver_topo'
//// @brief função que mostra qual elemento está no topo da pilha sem removê-lo
//// @param *pilha: ponteiro para a pilha em análise
//// @return p->vetor[p->topo]
int ver_topo(Pilha *pilha);

#endif