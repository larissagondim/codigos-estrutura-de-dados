/* Nome do arquivo: grafos.c
 * Autoria: Larissa Gondim
 * Data: 21/07/2026
 * Descrição: implementação das funções de grafos
 * Versão: 1.0
 */


#include "grafos.h"

/* Variáveis globais para o algoritmo DFS */
static int cnt;
int pre[Max];

/**
 * @brief Cria um novo nó para a lista de adjacência.
 * 
 * @param v Vértice destino.
 * @param prox Ponteiro para o próximo nó na lista.
 * @return AdjList Ponteiro para o nó recém-criado.
 */
AdjList novoNo(vertex v, AdjList prox) {
    AdjList a = malloc(sizeof(struct no));
    a->v = v;
    a->prox = prox;
    return a;
}

/**
 * @brief Inicializa a estrutura de um Grafo.
 * 
 * @param n_Vertices Quantidade de vértices do grafo.
 * @return Grafo Ponteiro para o grafo inicializado.
 */
Grafo initGrafo(int n_Vertices) {
    Grafo G = malloc(sizeof *G);
    G->Vertices = n_Vertices;
    G->Arestas = 0;
    G->adj = malloc(n_Vertices * sizeof(AdjList));
    for (vertex v = 0; v < n_Vertices; v++) {
        G->adj[v] = NULL;
    }
    return G;
}

/**
 * @brief Insere uma aresta bidirecional entre os vértices v e w.
 * 
 * @param G Ponteiro para o grafo.
 * @param v Vértice de origem.
 * @param w Vértice de destino.
 * @return int 1 em caso de sucesso, 0 se a aresta já existe.
 */
int insereAresta(Grafo G, vertex v, vertex w) {
    for (AdjList l = G->adj[v]; l != NULL; l = l->prox) {
        if (l->v == w) {
            printf("Aresta já existe \\n");
            return 0;
        }
    }
    G->adj[v] = novoNo(w, G->adj[v]);
    G->adj[w] = novoNo(v, G->adj[w]);
    G->Arestas++;
    return 1;
}

/**
 * @brief Exibe o grafo na saída padrão.
 * @param G Grafo a ser exibido.
 */
void printaGrafo(Grafo G) {
    printf("====Lista de Adjacencia=======\\n\\n");
    for (vertex v = 0; v < G->Vertices; v++) {
        printf("%d: ", v);  // imprime o vértice

        for (AdjList a = G->adj[v]; a != NULL; a = a->prox) {
            printf("%d -> ", a->v);  // imprime os vizinhos
        }

        printf("NULL\\n");  // fim da lista
    }
    printf("\\n\\n=============================\\n\\n");
}

/**
 * @brief Configura e inicia a Busca em Profundidade (DFS) em todos os vértices.
 * @param G Ponteiro para o grafo.
 */
void buscaDFS(Grafo G) {
    cnt = 0;
    for (vertex vex = 0; vex < G->Vertices; ++vex) {
        pre[vex] = -1;
    }
    for (vertex v = 0; v < G->Vertices; ++v) {
        if (pre[v] == -1)
            DFSRecursao(G, v);
    }
}

/**
 * @brief Passo recursivo da Busca em Profundidade (DFS).
 * @param G Ponteiro para o grafo.
 * @param v Vértice atual.
 */
void DFSRecursao(Grafo G, vertex v) {
    printf("Visitando vertice %d \\n", v);
    pre[v] = cnt++;
    for (AdjList a = G->adj[v]; a != NULL; a = a->prox) {
        vertex w = a->v;
        if (pre[w] == -1)
            DFSRecursao(G, w);
    }
}

/**
 * @brief Função principal para inicializar e testar o grafo.
 * @return int Retorna 0 indicando execução com sucesso.
 */
int main() {
    Grafo G = initGrafo(Max);
    insereAresta(G, 0, 1);
    insereAresta(G, 1, 2);
    insereAresta(G, 1, 4);
    insereAresta(G, 2, 3);
    printaGrafo(G);
    
    printf("Iniciando Busca em Profundidade\\n\\n");
    buscaDFS(G);
    return 0;
}