/* Nome do arquivo: matriz_tabuada.c
 * Autoria: Larissa Gondim
 * Data: 15/05/2026
 * Descrição: código que aloca tabuada dinamicamente e acessa resultado das multiplicações
 * Versão: 1.0
 * */

// includes necessários (apenas os padrão)
#include <stdio.h>
#include <stdlib.h>

// macros (tamanho da linha e coluna da tabuada)
#define TAM 10

// ---------- MAIN ----------
int main(void) {
    int i, j;
    
    // alocando espaço na memória para a tabuada
    int **tabuada = (int **) malloc(TAM * sizeof(int *));

    // verificando se a alocação foi sucessiva para a linha
    if(tabuada == NULL) 
        return 1;

    // em caso positivo, aloca espaço para as colunas e, também, realiza tais verificações
    for(i = 0; i < TAM; i++) {
        tabuada[i] = (int *) malloc(TAM * sizeof(int));
        if(tabuada[i] == NULL) {
            for(j = i-1; j >= 0; j--) 
                free(tabuada[j]);
            free(tabuada);
            return 1;
        }
    }

    // preenchendo tabuada caso toda a alocação tenha ocorrido sucessivamente
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) 
            tabuada[i][j] = (i+1) * (j+1);
    }

    // mostrando a tabuada: 
    printf("\nTabuada: ");
    for(i = 0; i < TAM; i++) {
        printf("\n[");
        for(j = 0; j < TAM-1; j++) {
            printf("%2d, ", tabuada[i][j]);
        }
        printf("%3d]", tabuada[i][j]);
    }
    // realizando operações na tabuada via índice
    char continuar = '1';
    while(continuar != '0') {
        int x, y;
        printf("\n\nInsira dois números entre 1 e 10 que você deseja multiplicar: ");
        scanf("%d %d", &x, &y);

        while((x < 1 || x > 10) || (y < 1 || y > 10)) {
            printf("\nInsira uma entrada válida: ");
            scanf("%d %d", &x, &y);
        }

        printf("\n\t%d x %d = %d\n", x, y, (tabuada[x-1][y-1]));

        printf("\nDeseja continuar? (1 para sim, 0 para não): ");
        scanf(" %c", &continuar);
    }
    
    // libera espaço na memória
    for(i = 0; i < TAM; i++) 
        free(tabuada[i]);
    free(tabuada);

    return 0;
}