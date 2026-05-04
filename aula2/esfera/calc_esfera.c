/*
 * Nome do arquivo: calc_esfera.c
 * Autoria: Larissa Gondim
 * Data: 04/05/2026
 * Descrição: Função que calcula volume e área de uma esfera
 * Versão: 1.1
 */

#include <stdio.h>
#include "calc_esfera.h"

void calc_esfera(float r, float* area, float* volume) {
    double pi = 3.1415;
    *area = 4*r*r*pi;
    *volume = (4*r*r*r)*pi/3.0;
}
