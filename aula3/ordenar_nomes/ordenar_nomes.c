#include <stdio.h>
#include <string.h>

#define MAX 100
#define ARQUIVO "pessoas.txt"

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

void salvar(Pessoa pessoas[], int n) {
    FILE *fp = fopen(ARQUIVO, "w");
    if (!fp) { perror("Erro ao salvar"); return; }

    for (int i = 0; i < n; i++)
        fprintf(fp, "%s %d\n", pessoas[i].nome, pessoas[i].idade);

    fclose(fp);
    printf("Salvo em '%s'.\n", ARQUIVO);
}

void listar(Pessoa pessoas[], int n) {
    if (n == 0) { printf("Nenhuma pessoa cadastrada.\n"); return; }
    printf("\n%-20s %s\n", "Nome", "Idade");
    printf("------------------------\n");
    for (int i = 0; i < n; i++)
        printf("%-20s %d\n", pessoas[i].nome, pessoas[i].idade);
    printf("\n");
}

int carregar(Pessoa pessoas[]) {
    FILE *fp = fopen(ARQUIVO, "r");
    if (!fp) return 0;

    int n = 0;
    while (fscanf(fp, "%49s %d", pessoas[n].nome, &pessoas[n].idade) == 2)
        n++;

    fclose(fp);
    return n;
}

int main() {
    Pessoa pessoas[MAX];
    int n = carregar(pessoas);
    int opcao;

    if (n > 0)
        printf("%d pessoa(s) carregada(s) do arquivo.\n", n);

    do {
        printf("\n1. Adicionar pessoa\n2. Listar\n3. Salvar e sair\nOpcao: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            if (n >= MAX) { printf("Limite atingido.\n"); continue; }

            printf("Nome: ");
            fgets(pessoas[n].nome, sizeof(pessoas[n].nome), stdin);
            pessoas[n].nome[strcspn(pessoas[n].nome, "\n")] = '\0';

            printf("Idade: ");
            scanf("%d", &pessoas[n].idade);
            getchar();

            n++;
            printf("Adicionado!\n");

        } else if (opcao == 2) {
            listar(pessoas, n);
        }

    } while (opcao != 3);

    salvar(pessoas, n);
    return 0;
}
