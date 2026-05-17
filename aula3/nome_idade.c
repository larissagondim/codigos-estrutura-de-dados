/* Nome do arquivo: nome_idade.c
 * Autoria: Larissa Gondim
 * Data: 04/05/2026 -> 17/05/2026
 * Descrição: código que adiciona o primeiro nome e a idade de pessoas em um arquivo 
 * Versão: 1.1 
 * */

#include <stdio.h>
#include <stdlib.h>

// macros (tamanho dos nomes)
#define TAM 21

// estrutura nome&idade para melhor estruturação dos dados
typedef struct {
    char nome[TAM];
    int idade;
} Pessoa;

// ---------- MAIN ----------
int main(void) {
    // cria ponteiro para arquivo, char para menu e para nome do arquivo
    FILE *fp;
    char escolha;
    char nome_arquivo[TAM];
    int n, i;

    printf("=== PREENCHE ARQUIVO ===");
    // garantia de entrada válida ANTES de prosseguir no fluxo
    do {
        printf("\nMenu\n0 - Adicionar conteudo a um arquivo pre-existente\n1 - Escrever num novo arquivo\nEscolha: ");
        scanf(" %c", &escolha);
    } while (escolha != '0' && escolha != '1');

    // personalização de arquivo que o usuário deseja modificar
    printf("\nInsira nome do arquivo que deseja modifica (com .txt no final): ");
    if(scanf(" %20[^\n]", nome_arquivo) != 1)
        return 1;

    // 'a' se for uma operação de adição, 'w' se for pra criar um do zero
    if(escolha == '0')
        fp = fopen(nome_arquivo, "a");
    else 
        fp = fopen(nome_arquivo, "w");

    // verifica se o arquivo pode ser aberto
    if(fp == NULL) {
        printf("\nErro ao abrir o arquivo.");
        return 1;
    }

    // número de pessoas que deseja inserir no arquivo
    printf("\nQuantas são as pessoas que você deseja inserir nome e idade? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("\nQuantidade invalida de pessoas.\n");
        fclose(fp);
        return 1;
    }

    // lógica de inserção
    for(i = 0; i < n; i++) {
        Pessoa p;
        printf("\nNome: ");
        scanf(" %20[^\n]", p.nome);

        printf("\nIdade: ");
        scanf("%d", &p.idade);

        // escreve no arquivo
        fprintf(fp, "Nome: %s | Idade: %d\n", p.nome, p.idade);
    }

    // fecha o arquivo após as operações terem sido concluídas
    fclose(fp);

    // se chegou ate aqui, o código funcionou
    printf("\nDados gravados com sucesso.\n");

    return 0;
} 
