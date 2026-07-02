// Nome do arquivo: arvore.h
// Autoria: Larissa Vilasboas Gondim
// Descrição: protótipo de funções de implementações de árvore binária
// Data: 01/07/2026
// Versão: 1.0

#ifndef ARVORE_H
#define ARVORE_H

// INCLUDES
// apenas os padrões
#include <stdio.h>
#include <stdlib.h>

// ESTRUTURAS

// 'no'
// representa o conteúdo presente nos ramos das árvores
typedef struct no {
    int conteudo;
    struct no *esq;
    struct no *dir;
} tNo;
typedef tNo *tArvBin;

// PROTÓTIPO DE FUNÇÕES AUXILIARES

// 'cria'
//// @brief cria uma árvore binária vazia alocando espaço para ela na memória
//// @param T ponteiro para o endereço de memória que a árvore será armazenada
//// @return a árvore vazia
void cria(tArvBin *T);

// 'vazia'
//// @brief verifica se a árvore está vazia ao verificar se a raiz está vazia
//// @param T a árvore que se deseja analisar
//// @return 1 se vazia, 0 caso contrário
int vazia(tArvBin T);

// 'busca'
//// @brief função que busca um elemento específico dentro de uma árvore binária
//// @param T a árvore na qual se deseja realizar a busca
//// @param dado a informação que se procura na árvore
//// @return o nó do elemento que foi encontrado e NULL caso não haja
tArvBin busca(tArvBin T, int dado);

// 'insereRaiz'
//// @brief insere novo nó na raiz da árvore
//// @param T árvore em análise
//// @param dado valor do nó a ser inserido na raiz
//// @return 1 caso a inserção seja bem-sucedida, 0 caso contrário
int insereRaiz(tArvBin *T, int dado);

// 'insereDireita'
//// @brief insere novo nó na direita de um nó existente
//// @param T árvore em análise
//// @param vPai valor do nó pai
//// @param vFilho valor do nó filho
//// @return 1 caso a inserção seja bem-sucedida, 0 caso contrário
int insereDireita(tArvBin *T, int vPai, int vFilho);

// 'insereEsquerda'
//// @brief insere novo nó na esquerda de um nó existente
//// @param T árvore em análise
//// @param vPai valor do nó pai
//// @param vFilho valor do nó filho
//// @return 1 caso a inserção seja bem-sucedida, 0 caso contrário
int insereEsquerda(tArvBin *T, int vPai, int vFilho);

// 'preordem'
//// @brief percorre a árvore exibindo os elementos em pré-ordem
//// @param T árvore em análise
//// @return nada pois é void
void preordem(tArvBin T);

// 'posordem'
//// @brief percorre a árvore exibindo os elementos em pós-ordem
//// @param T árvore em análise
//// @return nada pois é void
void posordem(tArvBin T);

#endif