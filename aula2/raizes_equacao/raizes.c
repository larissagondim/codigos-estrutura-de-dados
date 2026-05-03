#include <stdio.h>
#include <math.h>
#include "raizes.h" 

int raizes(float a, float b, float c, float* x1, float* x2) {
    float delta = (b*b - 4*a*c);
    if(delta < 0) 
	return 1;
    else if(fabsf(delta) < 1e-6) // aproximadamente zero 
        *x1 = *x2 = (-b/(2*a));
    else {
        *x1 = (-b + sqrtf(delta))/(2*a);
        *x2 = (-b - sqrtf(delta))/(2*a);
    }
    return 0;
}
