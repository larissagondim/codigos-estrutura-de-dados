
// includes (os padrões e a bibioteca math.h)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// protótipo de funções auxiliares
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
    int x, grau;
    printf("Insira o grau do polinômio: ");
    scanf("%d", &grau);
    printf("\nInsira o valor para qual o polinômio será avaliado: ");
    scanf("%d", &x);
    double *poli = (double *) malloc((grau + 1) * sizeof(double));
    // preenchendo os coeficientes do polinômio
    printf("\nInsira, respectivamente, os coeficientes do polinômmio: ");
    preenche(poli, (grau+1));
    // avaliando o polinômio naquelas condições específicas
    double resultado = avalia(poli, grau, x);
    printf("\nO resultado para o polinômio em análise foi: '%.2lf'\n", resultado);
    // liberando espaço na memória
    free(poli);
    return 0;
}

// corpo das funções auxiliares
double avalia(double *poli, int grau, double x) {
    double resultado = 0;
    for(int i = 0; i < (grau + 1); i++) 
        resultado += (poli[i] * pow(x, grau - i));
    return resultado;
}

void preenche(double *vet, int n) {
    double valor;
    for(int i = 0; i < n; i++) {
        scanf("%lf", &valor);
	vet[i] = valor;
    }
}
