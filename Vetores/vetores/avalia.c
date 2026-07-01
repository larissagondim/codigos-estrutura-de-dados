/* Nome do arquivo: avalia.c
 * Autoria: Larissa Gondim
 * Data: 12/05/2026
 * Descrição: código que avalia um polinômio num determinado ponto
 * Versão: 1.2
 */
// includes (os padrões e a bibioteca math.h)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// protótipo de funções auxiliares

int alocou(double *vet);
/* 'avalia'
 * @brief avalia polinômios para encontrar seus coeficientes
 * @param *poli conteúdo do ponteiro que aponta para o polinômio
 * @param grau grau do polinômio
 * @param x valor para qual o polinômio será avaliado
 * @return 
 * */
double avalia(double *poli, int grau, double x);

/* 'preenche'
 * @brief função que preenche um vetor
 * @param n tamanho do vetor
 * @param *vet conteudo do ponteiro que aponta para o vetor
 * @return nada pois é void
 * */
void preenche(double *vet, int n);
// ---------- MAIN ----------
int main(void) {
    // declarando as variáveis que serão utilizadas como parâmetros das funções utilizadas no código
    int grau;
    double x;

    // buscando os parâmetros e verificando se seguem o padrão desejado
    printf("Insira o grau do polinômio: ");
    scanf("%d", &grau);

    while(!(grau > 0)) {
        printf("Insira um grau válido (positivo)");
        scanf("%d", &grau);
    }

    printf("\nInsira o valor para qual o polinômio será avaliado: ");
    scanf("%lf", &x);

    // alocando dinamicamente espaço para os coeficientes do polinômio
    double *poli = (double *) malloc((grau + 1) * sizeof(double));

    // verifica se a alocação foi sucessiva
    if(!(alocou(poli))) {
        exit(1);
    } 

    // preenchendo os coeficientes do polinômio
    printf("\nInsira, respectivamente, os coeficientes do polinômmio em ordem crescente (se o grau for 3, vai do 1⁰, pro 2⁰ dai pro 3⁰, por exemplo): ");
    preenche(poli, (grau+1));

    // avaliando o polinômio naquelas condições específicas
    double resultado = avalia(poli, grau, x);
    printf("\nO resultado para o polinômio em análise foi: '%.2lf'\n", resultado);
    
    // liberando espaço na memória
    free(poli);
    return 0;
}

// corpo das funções auxiliares
int alocou(double *vet) {
    if(vet == NULL) {
        return 0;
    }
    return 1;
}

double avalia(double *poli, int grau, double x) {
    double resultado = 0;
    for(int i = 0; i < (grau + 1); i++) 
        resultado += (poli[i] * pow(x, i));
    return resultado;
}

void preenche(double *vet, int n) {
    double valor;
    for(int i = 0; i < n; i++) {
        scanf("%lf", &valor);
	    vet[i] = valor;
    }
}
