/* Nome do arquivo: fila_encadeada.h
 * Autoria: Larissa Gondim
 * Data: 17/06/2026
 * Descrição: arquivo de cabeçalho da implementação de fila com lista encadeada
 * Versão: 1.0
 */

#ifndef FILA_ENCADEADA_H
#define FILA_ENCADEADA_H

// INCLUDES
#include <stdlib.h>
#include <stdio.h>

// ESTRUTURAS

// 'No'
// representa cada nó da lista encadeada
// dado: valor armazenado no nó
// prox: ponteiro para o próximo nó
struct no {
    int dado;
    struct no* prox;
};
typedef struct no No;

// 'fila'
// representa a estrutura de fila com lista encadeada
// inicio: ponteiro para o primeiro elemento (frente)
// fim: ponteiro para o último elemento (traseira)
// tamanho: quantidade de elementos na fila
struct fila {
    No* inicio;
    No* fim;
    int tamanho;  // opcional, mas útil
};
typedef struct fila Fila;

// PROTÓTIPO DE FUNÇÕES

// 'cria_fila'
// @brief cria e inicializa uma fila vazia
// @param nada
// @return a fila recém criada
Fila* cria_fila(void);

// 'libera_fila'
// @brief libera toda a memória alocada pela fila
// @param **fila: ponteiro para a fila que será deletada
// @return nada pois é void
void libera_fila(Fila** fila);

// 'fila_vazia'
// @brief verifica se a fila está vazia
// @param *fila: ponteiro para a fila em análise
// @return 1 caso esteja vazia e 0 caso contrário
int fila_vazia(Fila* fila);

// 'enfileirar'
// @brief função que insere elemento no final da fila
// @param *fila: ponteiro para a fila
// @param elemento: elemento que será adicionado na fila
// @return 1 sempre (não tem limite de tamanho)
int enfileirar(Fila* fila, int elemento);

// 'desenfileirar'
// @brief função que remove elemento do início da fila
// @param *fila: ponteiro para a fila
// @param *elemento: ponteiro para guardar o elemento removido
// @return 1 se removeu com sucesso, 0 se fila vazia
int desenfileirar(Fila* fila, int* elemento);

// 'ver_frente'
// @brief função que mostra qual elemento está no início da fila sem removê-lo
// @param *fila: ponteiro para a fila em análise
// @return o valor do elemento da frente, ou -1 se vazia
int ver_frente(Fila* fila);

// 'tamanho_fila'
// @brief retorna quantos elementos estão na fila
// @param *fila: ponteiro para a fila em análise
// @return número de elementos na fila
int tamanho_fila(Fila* fila);

#endif