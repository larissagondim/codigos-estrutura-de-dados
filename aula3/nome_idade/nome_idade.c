/* Nome do arquivo: nome_idade.c
 * Autoria: Larissa Gondim
 * Data: 04/05/2026
 * Descrição: código que adiciona o nome e a idade de pessoas em um arquivo através de um loop
 * Versão: 1.0
 * */

#include <stdio.h>
// ==================== MAIN ====================
// variáveis:
// fp: ponteiro que guarda o endereço do local do arquivo
// n: número de pessoas que terão seus dados lidos
// idade: variável que armazenará as idades lidas
// nome: variável que armazenará os nomes lidos
// USAR DEPOIS ALOCAÇÃO DINÂMICA
int main(void) {
    FILE* fp = fopen("nome_idade.txt", "r+");
    int n, idade;
    char nome[21];
    printf("ADICIONE 'n' NOMES E IDADES NUM ARQUIVO\n");
    printf("Insira o número de pessoas que terão seus dados lidos: ");
    scanf("%d", &n);
    (void)getchar();
    for(int i = 0; i < n; i++){
        printf("Nome: ");
	fgets(nome, 21, stdin);
        nome[strcspn(nome, "\n")] = '\0';  // remove o \n
	fprintf(fp, "Nome: %s\n", nome);
	printf("Idade: ");
	scanf("%d", &idade);
	(void)getchar();
        fprintf(fp, "Idade: %d\n", idade);
    }
    fclose(fp);
    return 0;
} 
