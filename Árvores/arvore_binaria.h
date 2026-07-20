/* Nome do arquivo: arvore_binaria.h
 * Autoria: Larissa Gondim
 * Data: 20/07/2026
 * Descrição: arquivo de cabeçalho da implementação de árvore binária
 * Versão: 1.0
 */

#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

// INCLUDES
// apenas os padrão
#include <stdio.h>
#include <stdlib.h>

// ESTRUTURAS
// 'no'
// estrutura do nó que irá compor a árvore binária

typedef struct no {
    int conteudo;
    struct no *esq;
    struct no *dir;
} tNo;
typedef tNo *tArvBin;
// A separação entre o tipo do nó (tNo) e o tipo da árvore (tArvBin como ponteiro) 
// ocorre por questões práticas de semântica e eficiência na linguagem C.

// Como a árvore é uma estrutura recursiva, um ponteiro apontando para a raiz 
// é o suficiente para representar e acessar toda a hierarquia de descendentes. 
// Além disso, definir a árvore como um ponteiro permite indicar facilmente 
// que ela está vazia apenas atribuindo NULL a ela, o que seria impossível se 
// fosse uma struct direta. Por fim, ao passar a árvore para funções (como inserir ou buscar), 
// o uso do ponteiro evita a cópia desnecessária de dados na memória, tornando o 
// código mais rápido e permitindo a modificação direta da estrutura original.


// protótipo de funções auxiliares

// 'cria_arvore'
/// @brief cria uma árvore vazia
/// @param *T ponteiro para o local da memória que será armazenada a árvore
/// @return nada pois é void
void cria_arvore(tArvBin *T);

// 'eh_vazia'
/// @brief verifica se a árvore é vazia
/// @param T a árvore que se deseja analisar
/// @return 1 se vazia, 0 caso contrário
int eh_vazia(tArvBin T);

// 'busca_arv'
/// @brief busca elemento numa árvore
/// @param T a árvore na qual se deseja realizar a busca
/// @param dado o elemento que se deseja procurar
/// @return o endereço caso o elemento seja encontrado e NULL caso contrário
tArvBin busca_arv(tArvBin T, int dado);

// 'insere_raiz'
/// @brief insere um nó raíz numa árvore vazia
/// @param *T ponteiro para a árvore na qual se deseja realizar a inserção
/// @param dado valor que será inserido
/// @return 1 se houve a inserção, 0 caso contrário
int insere_raiz(tArvBin *T, int dado);

// 'insere_direita'
/// @brief insere um nó filho à direita de um dado nó
/// @param T árvore na qual se deseja realizar a inserção
/// @param vPai valor do no pai
/// @param vFilho valor do filho
/// @return 1 se houve a inserção, 0 caso contrário
int insere_direita(tArvBin T, int vPai, int vFilho);

// 'insere_esquerda'
/// @brief insere um nó filho à esquerda de um dado nó
/// @param T árvore na qual se deseja realizar a inserção
/// @param vPai valor do no pai
/// @param vFilho valor do filho
/// @return 1 se houve a inserção, 0 caso contrário
int insere_esquerda(tArvBin T, int vPai, int vFilho);

// funções de caminhamento

// 'exibe_preordem'
/// @brief exibe o conteúdo de uma árvore em préordem (pais -> filhos)
/// @param T a árvore que será exibida
/// @return nada pois é void
void exibe_preordem(tArvBin T);

// 'exibe_inordem'
/// @brief exibe o conteúdo de uma árvore em inordem (esquerda->raiz->direita)
/// @param T a árvore que será exibida
/// @return nada pois é void
void exibe_inordem(tArvBin T);

// 'exibe_posordem'
/// @brief exibe o conteúdo de uma árvore em préordem (filhos->pai)
/// @param T a árvore que será exibida
/// @return nada pois é void
void exibe_posordem(tArvBin T);
#endif