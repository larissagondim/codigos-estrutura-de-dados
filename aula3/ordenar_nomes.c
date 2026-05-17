/* Nome do arquivo: nome_idade.c
 * Autoria: Larissa Gondim
 * Data: 04/05/2026 -> 17/05/2026
 * Descrição: código que ordena nomes alfabeticamente num arquivo
 * Versão: 1.1
 */

// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// macros
#define TAM 21
#define MAX 100

// struct pessoa (para melhor estruturação do arquivo)
typedef struct {
    char nome[TAM];
    int idade;
} Pessoa;

// protótipo de funções auxiliares
// 'ordenar'
/// @brief função que ordena nomes alfabeticamente num arquivo
/// @param *arquivo ponteiro para o arquivo que será modificado
/// @return nada pois é void
void ordenar(FILE *arquivo);

// ---------- MAIN ----------
int main(void) {

    // VARIÁVEIS
    // nome_arquivo = armazena nome do arquivo que o usuário deseja alterar
    // c = char para facilitar leitura
    // *fp = ponteiro para arquivo desejado
    char nome_arquivo[TAM];
    int c;
    FILE *fp;

    printf("\nInsira o nome do arquivo que deseja modificar: ");

    if(scanf("%20s", nome_arquivo) != 1)
        return 1;

    // abre para leitura e escrita
    fp = fopen(nome_arquivo, "r+");

    if(fp == NULL) {
        printf("\nErro ao abrir o arquivo '%s'.\n", nome_arquivo);
        return 1;
    }

    // mostra arquivo antes
    printf("\nArquivo antes da ordenação:\n");
    while((c = fgetc(fp)) != EOF)
        printf("%c", c);

    // volta ao início
    rewind(fp);

    // ordena
    ordenar(fp);

    // volta ao início novamente
    rewind(fp);

    // mostra arquivo depois
    printf("\nArquivo depois da ordenação:\n");
    while((c = fgetc(fp)) != EOF)
        printf("%c", c);

    // fecha arquivo após operações
    fclose(fp);

    // se chegou até aqui, funcionou
    printf("\nDados ordenados com sucesso.");
    return 0;
}

// corpo das funções auxiliares
void ordenar(FILE *arquivo) {

    Pessoa pessoas[MAX];
    Pessoa temp;

    char linha[100];

    int qtd = 0;

    // leitura do arquivo
    while(fgets(linha, sizeof(linha), arquivo) != NULL) {

        if(sscanf(linha, "Nome: %20[^|]| Idade: %d", pessoas[qtd].nome, &pessoas[qtd].idade) == 2) {
            // remove espaço no final do nome
            int tam = strlen(pessoas[qtd].nome);

            if(pessoas[qtd].nome[tam - 1] == ' ')
                pessoas[qtd].nome[tam - 1] = '\0';

            qtd++;
        }
    }

    // ordenação Bubble Sort
    for(int i = 0; i < qtd - 1; i++) {
        for(int j = 0; j < qtd - 1 - i; j++) {
            if(strcmp(pessoas[j].nome, pessoas[j + 1].nome) > 0) {
                temp = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = temp;
            }
        }
    }

    // volta ao início
    rewind(arquivo);

    // reescreve ordenado
    for(int i = 0; i < qtd; i++) 
        fprintf(arquivo, "Nome: %s | Idade: %d\n", pessoas[i].nome, pessoas[i].idade);
    
}