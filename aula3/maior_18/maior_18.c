/* Nome do arquivo: maior_18.c
 * Autoria: Larissa Gondim
 * Data: 05/05/2026
 * Descrição: Mostrar nome de pessoas maiores de 18 anos num txt
 * Versão: 1.0
 * */

#include <stdio.h>
// ==================== MAIN ======================
int main() {
    int idade;
    char nome[21];
    FILE* fp = fopen("maior_18.txt", "r");
    for(int i = 0; i < 7; i++) {
        fscanf(fp, "%s\n%d\n", nome, &idade);
	if(idade > 18) printf("nome: %s | idade: %d\n", nome,idade);
    }
    fclose(fp);
    return 0;
}
