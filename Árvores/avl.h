/* Nome do arquivo: avl.h
 * Autoria: Larissa Gondim
 * Data: 21/07/2026
 * Descrição: arquivo de cabeçalho da implementação de AVL
 * Versão: 1.0
 */

#ifndef AVL_H
#define AVL_H

// INCLUDES
// apenas os padrão
#include <stdio.h>
#include <stdlib.h>

// ESTRUTURAS
// 'no'
// estrutura do nó que irá compor a árvore AVL

typedef struct no {
    int dado;
    int fb;
    struct no *esq;
    struct no *dir;
} tNo;
typedef tNo *tAVL;

// A separação entre o tipo do nó (tNo) e o tipo da árvore (tAVL como ponteiro) 
// ocorre por questões práticas de semântica e eficiência na linguagem C.

// Como a árvore é uma estrutura recursiva, um ponteiro apontando para a raiz 
// é o suficiente para representar e acessar toda a hierarquia de descendentes. 
// Além disso, definir a árvore como um ponteiro permite indicar facilmente 
// que ela está vazia apenas atribuindo NULL a ela, o que seria impossível se 
// fosse uma struct direta. Por fim, ao passar a árvore para funções (como inserir ou buscar), 
// o uso do ponteiro evita a cópia desnecessária de dados na memória, tornando o 
// código mais rápido e permitindo a modificação direta da estrutura original.


// protótipo de funções auxiliares

// 'cria'
/// @brief cria uma árvore AVL vazia
/// @param T ponteiro para o local da memória que será armazenada a árvore
/// @return nada pois é void
void cria(tAVL *T);

// 'eh_vazia'
/// @brief verifica se a árvore está vazia
/// @param T árvore AVL a ser verificada
/// @return 1 se estiver vazia (NULL), 0 caso contrário
int eh_vazia(tAVL T);

// 'exibe'
/// @brief exibe os elementos da árvore AVL em ordem crescente (in-order)
/// @param T árvore AVL a ser exibida
/// @return nada pois é void
void exibe(tAVL T);

// 'busca'
/// @brief busca um dado específico na árvore
/// @param T árvore AVL onde ocorrerá a busca
/// @param info o valor inteiro a ser procurado
/// @return ponteiro para o nó encontrado, ou NULL se o elemento não existir
tAVL busca(tAVL T, int info);

// 'insere'
/// @brief insere um novo elemento na árvore AVL e verifica o balanceamento
/// @param T ponteiro para a árvore AVL
/// @param item o valor a ser inserido
/// @return 1 se a inserção propagou mudança na altura, 0 caso contrário ou falha
int insere(tAVL *T, int item);

// 'rotacao_direita'
/// @brief realiza a rotação simples à direita em um nó desbalanceado
/// @param T ponteiro para o nó raiz da subárvore desbalanceada
/// @return nada pois é void
void rotacao_direita(tAVL *T);

#endif // AVL_H