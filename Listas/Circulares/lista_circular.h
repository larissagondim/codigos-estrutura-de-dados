/* Nome do arquivo: lista_circular.h
 * Autoria: Larissa Gondim
 * Data: 17/05/2026
 * Descrição: arquivo de cabeçalho da implementação de lista circular
 * Versão: 1.0
 */

#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

// includes
#include <stdio.h>
#include <stdlib.h>

// macros
#define TAM 10

// ESTRUTURAS: 

// 'lc'
// representa a estrutura comum de lista que será utilizada na lista circular
// inicio: ponteiro para o início da lista
// fim: ponteiro para o final da lista
// ctr: controle lógico do tamanho da lista
typedef struct {
    int ctri;
    int ctrf;
    int v[TAM];
} lc;

// PROTÓTIPO DE FUNÇÕES AUXILIARES

// 'esvazia_lista'
/// @brief função que inicializa/esvazia a lista circular, definindo os índices de início e fim como -1
/// @param *lista ponteiro para a lista circular que será inicializada
/// @return nada pois é void
void esvazia_lista(lc *lista);

// 'imprimir'
/// @brief função que imprime todos os elementos da lista circular na ordem lógica
/// @param *lista ponteiro para a lista circular que será exibida
/// @return nada pois é void
void imprimir(lc *lista);

// 'insercao_no_inicio'
/// @brief função que insere um novo elemento no início da lista circular
/// @param *lista ponteiro para a lista circular
/// @param num valor que será inserido
/// @return nada pois é void
void insercao_no_inicio(lc *lista, int num);

// 'insercao_no_final'
/// @brief função que insere um novo elemento no final da lista circular
/// @param *lista ponteiro para a lista circular
/// @param num valor que será inserido
/// @return nada pois é void
void insercao_no_final(lc *lista, int num);

// 'insercao_no_meio'
/// @brief função que insere um novo elemento em uma posição específica da lista circular
/// @param *lista ponteiro para a lista circular
/// @param pos posição lógica onde o elemento será inserido
/// @param num valor que será inserido
/// @return nada pois é void
void insercao_no_meio(lc *lista, int pos, int num);

// 'lista_cheia'
/// @brief função que verifica se a lista circular está cheia
/// @param *lista ponteiro para a lista circular
/// @return 1 caso a lista esteja cheia e 0 caso contrário
int lista_cheia(lc *lista);

// 'lista_vazia'
/// @brief função que verifica se a lista circular está vazia
/// @param *lista ponteiro para a lista circular
/// @return 1 caso a lista esteja vazia e 0 caso contrário
int lista_vazia(lc *lista);

#endif