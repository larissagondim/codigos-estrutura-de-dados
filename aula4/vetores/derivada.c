/* Nome do arquivo: deriva.c
 * Autoria: Larissa Gondim
 * Data: 12/05/2026
 * Descrição: código que calcula a derivada de um polinômio definido pelo usuário
 * Versão: 1.0
 */

// includes (apenas as bibliotecas padrão)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// funções auxiliares
/* @brief função que calcula a derivada de um polinômio definido pelo usuário
 * @param poli conteúdo do ponteiro que aponta para os coeficientes do polinômio (decrescente em relação ao grau)
 * @param grau representa o grau do polinômio
 * @param out representa os coeficientes do polinômio derivado (também decrescente em relação ao grau)
 * @return nada pois é void
 */
void deriva(double* poli, int grau, double *out);

// ---------- MAIN ----------
int main(void) {
    float  
    return 0;
}

// corpo das funções auxiliares
void deriva(double* poli, int grau, double *out) {
    for(int i = grau; i > 0; i--) {
        out[grau-i] = i * poli[grau - i];
    }
}
