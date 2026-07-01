#ifndef DENTRO_RET_H
#define DENTRO_RET_H
/**
 * @brief determina se certo ponto está ou não dentro de um retângulo
 * @param x0 determina coordenada x do vértice inferior esquerdo
 * @param y0 determina coordenada y do vértice inferior esquerdo
 * @param x1 determina coordenada x do vértice superior direito
 * @param y1 determina coordenada y do vértice superior direito
 * @param x primeira coordenada do ponto
 * @param y segunda coordenada do ponto
 * @return retorna 1 se tiver dentro do retângulo e 0 caso não
 */
int dentro_ret(int x0, int y0, int x1, int y1, int x, int y);

#endif