/* Nome do arquivo: abp.h
 * Autoria: Larissa Gondim
 * Data: 20/07/2026
 * Descrição: arquivo de cabeçalho da implementação de árvore binária de pesquisa
 * Versão: 1.0
 */

#ifndef ABP_H
#define ABP_H

// INCLUDES
// apenas os padrão
#include <stdio.h>
#include <stdlib.h>

// ESTRUTURAS

// 'tAbp'
// estrurura da árvore binária de pesquisa

typedef struct no {
    int info;
    struct no *esq;
    struct no *dir;
} tNo;
typedef tNo *tAbp;

// FUNÇÕES AUXILIARES

// 'cria_arvore'
/// @brief função que cria arvore binária de pesquisa
/// @param *T ponteiro para o local na memória que a árvore será armazenada
/// @return nada pois é void
void cria_arvore(tAbp *T);

// 'eh_vazia'
/// @brief função que verifica se a árvore está vazia
/// @param T a árvore na qual se deseja verificar
/// @return 1 se vazia, 0 caso contrário
int eh_vazia(tAbp T);

// 'busca'
/// @brief função que busca elemento numa ABP
/// @param T a árvore na qual se deseja realizar a busca
/// @param dado informação que se deseja buscar
/// @return nó com o dado
tAbp busca(tAbp, int dado);

// 'exibe'
/// @brief função que exibe ABP da esquerda para a direita
/// @param T árvore que se deseja buscar
/// @return nada pois é void
void exibe(tAbp T);

// 'insere'
/// @brief função para inserção em ABP
/// @param *T ponteiro para a árvore na qual se deseja inserir
/// @param item item que se deseja inserir
/// @return 1 caso a inserção seja sucessiva, 0 caso contrário
int insere(tAbp *T, int item);
#endif