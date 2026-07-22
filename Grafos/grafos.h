/* Nome do arquivo: grafos.h
 * Autoria: Larissa Gondim
 * Data: 21/07/2026
 * Descrição: protótipos das funções de grafos
 * Versão: 1.0
 */

#ifndef GRAFO_H
#define GRAFO_H

// include -> apenas os padrão
#include <stdio.h>
#include <stdlib.h>

// MACROS
// limite de vértices
#define Max 100 

/**
 * @brief Definição do tipo para representar um vértice.
 */
typedef int vertex;

/**
 * @brief Estrutura do nó para a lista de adjacência.
 */
typedef struct no *AdjList;
struct no {
    vertex v;       /**< Vértice destino da aresta. */
    AdjList prox;   /**< Ponteiro para o próximo nó da lista de adjacência. */
};

/**
 * @brief Estrutura principal do Grafo.
 */
typedef struct grafo *Grafo;
struct grafo {
    int Vertices;   /**< Número total de vértices no grafo. */
    int Arestas;    /**< Número total de arestas no grafo. */
    AdjList *adj;   /**< Vetor de listas de adjacência. */
};

/* =========================================
 *           Protótipos de Funções
 * ========================================= */

/**
 * @brief Cria um novo nó para a lista de adjacência.
 * @param v Vértice destino.
 * @param prox Ponteiro para o próximo nó na lista.
 * @return AdjList Ponteiro para o novo nó criado.
 */
AdjList novoNo(vertex v, AdjList prox);

/**
 * @brief Inicializa um novo grafo com um número específico de vértices.
 * @param n_Vertices Número de vértices que o grafo terá.
 * @return Grafo Ponteiro para a estrutura do grafo recém-criado.
 */
Grafo initGrafo(int n_Vertices);

/**
 * @brief Insere uma aresta não-direcionada entre dois vértices no grafo.
 * @param G Ponteiro para o grafo.
 * @param v Vértice de origem.
 * @param w Vértice de destino.
 * @return int Retorna 1 se a aresta foi inserida com sucesso, ou 0 se já existia.
 */
int insereAresta(Grafo G, vertex v, vertex w);

/**
 * @brief Imprime a representação do grafo em formato de lista de adjacência.
 * @param G Ponteiro para o grafo a ser impresso.
 */
void printaGrafo(Grafo G);

/**
 * @brief Inicializa e dispara a Busca em Profundidade (DFS - Depth-First Search) 
 *        para todos os componentes do grafo.
 * @param G Ponteiro para o grafo.
 */
void buscaDFS(Grafo G);

/**
 * @brief Função auxiliar recursiva para a Busca em Profundidade (DFS).
 * @param G Ponteiro para o grafo.
 * @param v Vértice atual sendo visitado.
 */
void DFSRecursao(Grafo G, vertex v);

#endif /* GRAFO_H */