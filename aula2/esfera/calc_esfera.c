#include <stdio.h>
#include "calc_esfera.h"

void calc_esfera(float r, float* area, float* volume) {
    *area = 4*r*r;
    *volume = (4*r*r*r)/3.0;
}
