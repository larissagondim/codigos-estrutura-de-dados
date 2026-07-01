/*
 * Nome do arquivo: leibniz.c
 * Autoria: Larissa Gondim
 * Data: 29/04/2026
 * Descrição: Função que utiliza da fórmula de Leibniz com N fatores para calcular uma aproximação de pi
 * Versão: 1.0
 */
#include <stdio.h>
#include "leibniz.h"

double leibniz(int n) {
    double pi = 0.0;
    int sinal = 1;
    for(int i = 0; i < n; i++) {
	pi += sinal * ((double)1 / (2*i + 1));
	sinal *= -1;
    }
    pi *= 4;
    return pi;
}
