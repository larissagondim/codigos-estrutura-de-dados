/*                                                                                                                                                                                                                    * Nome do arquivo: conta_vogal.c
 * Autor: Larissa Gondim
 * Data: 11/05/2026
 * Descrição: Programa que conta vogais de um vetor
 * Versão: 1.1
 */

// includes:
// stdio.h -> biblioteca padrao de input e output da linguagem c
// stdlib.h -> biblioteca padrão de C, importada para utilizar 'malloc'
// string.h -> biblioteca para mannipulação de string (vetor de caracteres)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// funções auxiliares
/**
 * 'alocou'
 * @brief função que verifica se houve efetivfamente a alocação dinâmica do vetor
 * @param *p: ponteiro que aponta pro vetor em análise
 * @return 1 caso tenha sido propriamente alocada, 0 caso contrário 
 */
int alocou(char *p);

/**
 * 'alocou'
 * @brief função que preenche vetor alocado dinamicamente
 * @param *p: ponteiro que aponta pro vetor em análise
 * @return nenhum pois é void
 */
void preenche(char *p, int tam);

/**
 * 'alocou'
 * @brief função que conta quantas são as vogais presentes no vetor
 * @param *p: ponteiro que aponta pro vetor em análise
 * @return o número de vogais
 */
int conta_vogais(char *p, int tam);

/**
 * 'alocou'
 * @brief função que printa o vetor
 * @param *p: ponteiro que aponta pro vetor em análise
 * @return nada pois é void
 */
void mostra_vetor(char *p, int tam);

// ========== MAIN ==========
int main(void) {
    int n, n_vogais;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    char *p = malloc(n * sizeof(char));

    // verificando se a alocação foi feita corretamente
    if (!alocou(p)) 
        free(p);

    // preenche a matriz alocada dinamicamente
    printf("\nPreencha caractere por caractere: ");
    preenche(p, n);
    
    // mostra quantas são as vogais
    n_vogais = conta_vogais(p, n);
    printf("\nO número de vogais no vetor '");
    mostra_vetor(p, n);
    printf("' é dado por: '%d'\n", n_vogais);

    // libera ponteiro
    free(p);
    return 0;
}

int alocou(char *p) {
    if(p == NULL) {
        printf("Falha na alocação de memória");
        return 0;
    }
    return 1;
}

void preenche(char *p, int tam) {
    for(int i = 0; i < tam; i++) 
        scanf(" %c", &p[i]);
}

int conta_vogais(char *p, int tam) {
    int numero_vogais = 0;
    for(int i = 0; i < tam; i++) {
        if(p[i] == 'a' || p[i] == 'e' || p[i] == 'i' || p[i] == 'o' || p[i] == 'u' || p[i] == 'A' || p[i] == 'E' || p[i] == 'I' || p[i] == 'O' || p[i] == 'U') {
            numero_vogais += 1;
        } 
    }
    return numero_vogais;
}

void mostra_vetor(char *p, int tam) {
    int i;
    for(i = 0; i < tam; i++)
        printf("%c", p[i]);
}