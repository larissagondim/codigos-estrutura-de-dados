/* Nome do arquivo: fila.h
 * Autoria: Larissa Gondim
 * Data: 15/06/2026
 * Descrição: arquivo de cabeçalho da implementação de fila estática
 * Versão: 1.0
 */

#ifndef FILA_H
#define FILA_H

// MACROS
// MAX: tamanho da fila
#define MAX 50

// INCLUDES
// apenas os padrão
#include <stdlib.h>
#include <stdio.h>

// ESTRUTURAS

// 'fila'
// representa a estrutura de fila que será utilizada nas implementações
// inicio: índice do primeiro elemento (frente)
// fim: índice do último elemento (traseira)
// vetor[MAX]: elementos da fila
struct fila {
    int inicio;
    int fim;
    int vetor[MAX];
};
typedef struct fila Fila;

// PROTÓTIPO DE FUNÇÕES AUXILIARES

// 'cria_fila'
//// @brief cria e inicializa uma fila vazia
//// @param nada
//// @return a fila recém criada
Fila *cria_fila(void);

// 'libera_fila'
//// @brief cria e inicializa uma fila vazia
//// @param **fila ponteiro para a fila que será deletada
//// @return nada pois é void
void libera_fila(Fila **fila);

// 'fila_cheia'
//// @brief verifica se a fila está cheia
//// @param *fila: ponteiro para a fila em análise
//// @return 1 caso esteja cheia e 0 caso contrário
int fila_cheia(Fila *fila);

// 'fila_vazia'
//// @brief verifica se a fila está vazia
//// @param *fila: ponteiro para a fila em análise
//// @return 1 caso esteja vazia e 0 caso contrário
int fila_vazia(Fila *fila);

// 'enfileirar'
// @brief função que insere elemento no final da fila
// @param *fila: ponteiro para a fila
// @param elemento: elemento que será adicionado na fila
// @return 0 caso a fila esteja cheia e 1 caso contrário (elemento adicionado)
int enfileirar(Fila *fila, int elemento);

// @param *fila: ponteiro para a fila
// @param *elemento: ponteiro para guardar o elemento removido
// @return 0 caso a fila esteja vazia e 1 caso contrário
int desenfileirar(Fila *fila, int *elemento);

// 'ver_frente'
// @brief função que mostra qual elemento está no início da fila sem removê-lo
// @param *fila: ponteiro para a fila em análise
// @return retorna o valor do elemento da frente, ou -1 se vazia
int ver_frente(Fila *fila);

// 'tamanho_fila'
// @brief calcula quantos elementos estão na fila no momento
// @param *fila: ponteiro para a fila em análise
// @return número de elementos na fila
int tamanho_fila(Fila *fila);

#endif