/* Nome do arquivo: deriva.c
 * Autoria: Larissa Gondim
 * Data: 12/05/2026
 * Descrição: código que calcula a derivada de um polinômio definido pelo usuário
 * Versão: 1.1
 */

// includes (apenas as bibliotecas padrão)
#include <stdio.h>
#include <stdlib.h>

// protótipos das funções auxiliares:

/* @brief função que verifica se a alocação dinâmica pro espaço do vetor ocorreu efetivamente
 * @param vet ponteiro que se deseja verificar
 * @return 1 caso tenha ocorrido, 0 se não
 */
int alocou(double *vet);
/* @brief função que calcula a derivada de um polinômio definido pelo usuário
 * @param poli conteúdo do ponteiro que aponta para os coeficientes do polinômio (decrescente em relação ao grau)
 * @param grau representa o grau do polinômio
 * @param out representa os coeficientes do polinômio derivado (também decrescente em relação ao grau)
 * @return nada pois é void
 */
void deriva(double* poli, int grau, double *out);

/* @brief função que printa o conteúdo de um vetor
 * @param vet vetor que se deseja printar
 * @param tam tamanho desse vetor
 * @return nada pois é void
 */
void mostra(double *vet, int tam);

/* @brief função que insere valores em um vetor
 * @param vet vetor que se deseja realizar a operação
 * @param tam tamanho desse vetor
 * @return nada pois é void
 */
void preenche(double *vet, int tam);

// ---------- MAIN ----------
int main(void) {
    int grau;
    // buscando os parâmetros das funções
    printf("Insira o grau do polinômio: ");
    scanf("%d", &grau);

    // como o grau deve ser estritamente positivo, irei fazer o sistema verificar tal condição
    while(!(grau > 0)) {
        printf("\nInsira um grau válido (positivo): ");
        scanf("%d", &grau);
    }

    // alocando dinamicamente espaço para os coeficientes do polinômio e para suas derivadas:
    double *p = (double *) malloc((grau + 1) * sizeof(double));
    double *out = (double *) malloc((grau) * sizeof(double));
    
    // verificando se foi sucessiva a alocação
    if(!alocou(p) || !alocou(out)) 
        exit(1);
    
    // preenchendo os coeficientes do polinômio:
    printf("\nAgora preencha os coeficientes desse polinômio: ");
    preenche(p, (grau+1));
    // caso tenha sido efetiva, mostra os coeficientes do polinômio e calcula a derivada  
    printf("\nCoeficientes do polinômio antes da derivação: ");
    mostra(p, (grau+1));
    deriva(p, grau, out);

    // agora mostra os coeficientes após a derivação
    printf("\nCoeficientes do polinômio após a derivação: ");
    mostra(out, grau);

    // liberando o espaço de memória que foi alocado para ambos os vetores
    free(p);
    free(out);
    return 0;
}

// corpo das funções auxiliares

int alocou(double *vet) {
    if(vet == NULL)
        return 0;
    return 1; 
}

void deriva(double* poli, int grau, double *out) {
    for(int i = grau; i > 0; i--) {
        out[grau-i] = i * poli[grau - i];
    }
}

void mostra(double *vet, int tam) {
    int i;
    printf("{");
    for(i = 0; i < tam - 1; i++) 
        printf("%.2lf, ", vet[i]);
    printf(" %.2lf}", vet[i]);
}

void preenche(double *vet, int tam) {
    for(int i = 0; i < tam; i++) {
        scanf("%lf", &vet[i]);
    }
}