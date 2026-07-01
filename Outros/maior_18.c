/* Nome do arquivo: maior_18.c
 * Autoria: Larissa Gondim
 * Data: 05/05/2026 -> 17/05/2026
 * Descrição: Mostrar nome de pessoas maiores de idade num txt
 * Versão: 1.1
 * */

// includes (apenas os padrão)
#include <stdio.h>
#include <stdlib.h>

// macros (tamanho das strings)
#define TAM 21

// struct para melhor organização dos dados no arquivo
typedef struct {
    char nome[TAM];
    int idade;
} Pessoa;

// ---------- MAIN ----------
int main(void) {
    // variáveis:

    // nome_arquivo = string que armazena nome do arquivo a ser percorrido
    // linha = string que armazena a linha do arquivo lido
    // *fp = ponteiro para o arquivo
    // p = struct pessoa (para estruturar a leitura do arquivo)
    char nome_arquivo[TAM], linha[100];
    FILE *fp;
    Pessoa p;

    // usuário insere nome do arquivo
    printf("\nInsira o nome do arquivo que deseja percorrer: ");
    if(scanf("%20[^\n]", nome_arquivo) != 1) 
        return 1;

    // abre o arquivo no modo leitura
    fp = fopen(nome_arquivo, "r");

    // se o ponteiro estiver vazio, retorna mensagem de erro
    if(fp == NULL) {
        printf("\nErro ao abrir o arquivo '%s'", nome_arquivo);
        return 1;
    }

    // lógica de leitura do arquivo
    // enquanto a linha não estiver vazia, lê e aplica as condições
    while(fgets(linha, sizeof(linha), fp) != NULL) {
        if(sscanf(linha, "Nome: %20[^|] | Idade: %d", p.nome, &p.idade) == 2) {
            if(p.idade >= 18)
                printf("\nNome:%s | Idade: %d", p.nome, p.idade);
        }
    }

    // fecha o arquivo após as operações
    fclose(fp);

    // se chegou até aqui, funcionou
    printf("\nDados lidos com sucesso.");

    return 0;
}
