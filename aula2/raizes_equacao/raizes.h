#ifndef RAIZES_H
#define RAIZES_H
/*@brief função que calcula as raízes de uma equação do segundo grau
 * @param a coeficiente do x^2
 * @param b coeficiente do x
 * @param c constante
 * @param x1 endereço da primeira raíz da equação
 * @param x2 endereço da segunda raíz da equação
 * @return 0 se tiver raiz, 1 se não tiver
 * */
int raizes(float a, float b, float c, float* x1, float* x2);

#endif
