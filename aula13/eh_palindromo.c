/* Nome do arquivo: eh_palindromo.c
 * Autoria: Larissa Gondim
 * Data: 17/06/2026
 * Descrição: código que verifica se uma string é um palíndromo
 * Versão: 1.0
 * */

#include "fila.h"
#include <string.h>

#define TAM 100

int main(void) {
    Fila *f1, *f2;
    char str[TAM];
    int elemento1, elemento2;  // Usando int como a fila espera
    
    // cria duas filas
    f1 = cria_fila();
    f2 = cria_fila();
    
    if (f1 == NULL || f2 == NULL) {
        printf("\nErro ao criar filas!\n");
        return 1;
    }
    
    // leitura da string a ser verificada
    printf("\nDigite uma string: ");
    scanf("%s", str);
    
    int len = strlen(str);
    
    // preenche primeira fila com elementos da string
    for (int i = 0; i < len; i++)    
        enfileirar(f1, (int)str[i]);  // cast explícito para int
    
    // preenche segunda fila com elementos da string de trás pra frente
    for (int j = len - 1; j >= 0; j--)
        enfileirar(f2, (int)str[j]);
    
    // compara as filas
    while (!fila_vazia(f1)) {
        elemento1 = ver_frente(f1);
        elemento2 = ver_frente(f2);
        
        if (elemento1 != elemento2) {
            printf("\nNao eh palindromo\n");
            libera_fila(&f1);
            libera_fila(&f2);
            return 0;
        }
        
        desenfileirar(f1, &elemento1);
        desenfileirar(f2, &elemento2);
    }
    
    printf("\nEh palindromo\n");
    
    libera_fila(&f1);
    libera_fila(&f2);
    
    return 0;
}