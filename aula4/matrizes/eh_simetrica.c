/* Nome do arquivo: eh_simetrica.c                                                                                                                                                                                                                  
 * Autoria: Larissa Gondim
 * Data: 12/05/2026
 * Descrição: Programa que verifica se matriz é quadrada e simétrica
 * Versão: 1.1
 */

// includes (apenas as bibliotecas padrão)
#include <stdio.h>
#include <stdlib.h>

// protótipo das funções auxiliares

/* 'eh_simetrica'
* @brief função que verifica se uma matriz é quadrada e simétrica
* @param **p ponteiro que aponta para a matriz na memória
* @param m número de linhas da matriz
* @param n número de colunas da matriz
* @return 1 se for simétrica, 0 caso contrário
*/
int eh_quadrada_e_simetrica(int **p, int m, int n);

/* 'mostra_matriz'
* @brief função que mostra a matriz no terminal
* @param **p ponteiro que aponta para a matriz na memória
* @param m número de linhas da matriz
* @param n número de colunas da matriz
* @return nada pois é void
*/
void mostra_matriz(int **matriz, int m, int n);

/* 'libera'
* @brief função que libera matriz na memória
* @param **p ponteiro que aponta para a matriz na memória
* @param m número de linhas da matriz
* @return nada pois é void
*/
void libera_matriz(int **matriz, int m);

// ---------- MAIN ----------
int main(void) {
    // buscando o tamanho da matriz de acordo com a inserção do usuário e verificando se a entrada é válida
    int m, n;

    printf("\nInsira o número de linhas da matriz: ");
    scanf("%d", &m);
    while(!(m > 0)) {
        printf("\nInsira um número válido de linhas (positivo): ");
        scanf("%d", &m);
    }

    printf("\nInsira o número de colunas da matriz: ");
    scanf("%d", &n);
    while(!(n > 0)) {
        printf("\nInsira um número válido de linhas (positivo): ");
        scanf("%d", &n);
    }

    // alocando, dinamicamente, espaço para a matriz na memória
    int **matriz = (int **) malloc(m * sizeof(int *));

    // verificando se as linhas foram alocadas sucessivamente
    if(matriz == NULL) {
        printf("\nErro na alocação de memória das linhas da matriz!");
        exit(1);
    }

    // caso as linhas tenham sido alocadas propriamente, agora para a alocação das respectivas colunas
    for (int i = 0; i < m; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
        if (matriz[i] == NULL) {
            libera_matriz(matriz, i);
            exit(1);
        }
    }

    // preenchendo a matriz
    printf("\nPreenchendo a matriz %dx%d", m, n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("\nElemento matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    // mostrando matriz em análise:
    printf("\nMatriz %dx%d: ", m, n);
    mostra_matriz(matriz, m, n);

    // verificando se é quadrada e simétrica verificando simetria
    if(eh_quadrada_e_simetrica(matriz, m, n)) 
        printf("\nA matriz é quadrada e simétrica!");
    else {
        if(m == n)
            printf("\nApesar de quadrada, a matriz não é simétrica");
        else
            printf("\nA matriz não é quadrada, portanto, é impossível ser simétrica");
    }
    // liberando o espaço na memória
    libera_matriz(matriz, m);

    return 0;
}

// corpo das funções auxiliares
int eh_quadrada_e_simetrica(int **matriz, int m, int n) {
    if(m != n)
        return 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matriz[i][j] != matriz[j][i]) 
                return 0;
        }
    }
    
    return 1;
}

void mostra_matriz(int **matriz, int m, int n) {
    int i, j;
    for(i = 0; i < m; i++) {
        printf("\n[");
        for(j = 0; j < n-1; j++) 
            printf("%d, ", matriz[i][j]);
        printf("%d]", matriz[i][j]);
    }
}

void libera_matriz(int **matriz, int m) {
    if (matriz == NULL) return;
    for (int i = 0; i < m; i++) 
        free(matriz[i]);
    free(matriz);
}