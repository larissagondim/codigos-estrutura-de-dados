/* Nome do arquivo: lista_encadeada.h
 * Autoria: Larissa Gondim
 * Data: 03/06/2026
 * Descrição: código que guarda protótipos de funções de manipulação de lista encadeada
 * Versão: 1.0
 * */

#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

// includes necessários
#include <stdio.h>
#include <stdlib.h>

// ESTRUTURAS

// 'no'
// estrutura que representa os elementos da lista, compostos por 2 ponteiros e uma informação
// 'info': parâmetro que guarda o valor do nó
// 'prox': ponteiro para o próximo nó
// 'ante': ponteiro para o nó anterior
typedef struct no {
    int info;
    No *prox;
    No *ante;   
} No;

// 'lista'
// estrutura que representa elementos da lista, composta por 2 ponteiros para nós
// 'inicio': representa o primeiro nó da lista (ou seja, o primeiro elemento)
// 'fim': representa o último nó da lista (ou seja, o último elemento)
typedef struct lista {
    No *inicio;
    No *fim;
} Lista;

// PROTÓTIPO DE FUNÇÕES AUXILIARES

// funções de criação

// 'cria_no'
// @brief função responsável por alocar memória dinamicamente para a criação de um nó
// @param info: valor que será armazenado pelo nó
// @return o nó que foi criado
No *cria_no(int info);

// 'cria_lista'
// @brief função responsável por alocar memória dinamicamente para a criação de uma lista
// @param void
// @return a lista recém criada
Lista cria_lista(void);

// funções de inserção

// 'insere_inicio'
// @brief função de inserção de valores no início da lista encadeada
// @param ll: lista que terá modificações
// @param valor: valor a ser inserido
// @return 0 caso a alocação do novo nó não tenha sido sucessiva, 1 em caso positivo
int insere_inicio(Lista *ll, int valor);

// 'insere_fim'
// @brief função de inserção de valores no fim da lista encadeada
// @param ll: lista que terá modificações
// @param valor: valor a ser inserido
// @return 0 caso a alocação do novo nó não tenha sido sucessiva, 1 em caso positivo
int insere_fim(Lista *ll, int valor);

// PS: falta implementar a partir daquig

// 'insere_meio'
// @brief função de inserção de valores no meio da lista encadeada
// @param ll: a lista que será modificada
// @param pos: a posição de inserção do elemento na lista
// @param valor: valor a ser inserido
// @return 0 caso a alocação do novo nó não tenha sido sucessiva, 1 em caso positivo
int insere_meio(Lista *ll, int pos, int valor);

// funções de remoção

int remove_inicio(Lista *ll);

int remove_fim(Lista *ll);

int remove_meio(Lista *ll);
#endif