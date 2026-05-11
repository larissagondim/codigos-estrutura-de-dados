/*                                                                                                                                                                                                                    * Nome do arquivo: vetor.c
 * Autor: Larissa Gondim
 * Data: 06/05/2026
 * Descrição: Manipulando matrizes com alocação dinâmica de memória
 * Versão: 1.1
 */
#include <stdio.h>
#include <stdlib.h>
// funções
/* @brief função que printa a matriz corretamente
 * @var **p: ponteiro duplo para a matriz
 * @return nada pois é void
 * */
void printa_matriz(int **p);
// MACROS:
#define N 3 // define o tamanho do vetor
// ========== MAIN ==========
// a main realiza a implementação de diversas operações com vetores com alocação dinâmica de memória
// retorno: 0 em caso de sucesso e 1 caso haja alguma incongruência ao longo da implementação
int main(void) {
    int i, j, valor;
    int **p = (int**)malloc(N * sizeof(int*));
    if(!p) return 1;
    // verificando se a alocação foi realizada propriamente
    for(i = 0; i < N; i++) {
        p[i] =  (int*) malloc(N*sizeof(int));
        if(!p[i]) break;         
    }
    // caso a alocação não tenha sido realizada propriamente, libera os espaços de p;
    if(i < N) {
	for(i = i - 1; i >= 0; i--) 
            free(p[i]);	
        free(p);
    }
    // preenchendo a matriz alocada dinâmicamente
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            scanf("%d", &valor);
	    p[i][j] = valor;
	}
    }
    // mostrando a matriz
    printa_matriz(p);
    return 0;
}
// colocando os comandos da função previamente prototipada
void printa_matriz(int **p) {
    int i, j;
    printf("MATRIZ %dX%d: \n", N, N);
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
	    printf("%d ", p[i][j]);
        }
	printf("\n");
    }

}
