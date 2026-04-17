# Revisão para Estrutura de Dados: Vetores em C

## Motivação

A revisão de vetores é um passo fundamental para a disciplina de **Estrutura de Dados**. Em C, o domínio sobre arrays não é apenas sobre armazenar dados, mas sobre entender como o computador manipula a memória de forma contígua. Aqui vão alguns motivos importantes para a revisão:

1.  **Fundamento para Estruturas Dinâmicas:** Antes de implementar Listas Encadeadas, Pilhas ou Filas, é preciso entender como a aritmética de ponteiros funciona dentro de um bloco de memória (vetor).
2.  **Conexão com Arquitetura de Computadores:** O funcionamento dos vetores reflete diretamente o uso de instruções de `load` e `store` em **Assembly (RISC-V/MIPS)**, onde calculamos o deslocamento (*offset*) para acessar elementos.
3.  **Eficiência Algorítmica:** Revisar vetores permite fixar conceitos de complexidade de tempo ($O(1)$ para acesso, $O(n)$ para busca e inserção), essenciais para o desempenho em programação competitiva.

-----

## Exercícios para consolidação do conteúdo

Para consolidar a lógica de manipulação de índices e memória, vou resolver os seguintes problemas da plataforma `Beecrowd`: 

| ID | Problema | Foco do Treino | Status |
| :--- | :--- | :--- | :--- |
| **1172** | [Substituição em Vetor I](https://www.google.com/search?q=https://www.beecrowd.com.br/judge/pt/problems/view/1172) | Iteração básica e condicionais. | ✅  |
| **1173** | [Preenchimento de Vetor I](https://www.google.com/search?q=https://www.beecrowd.com.br/judge/pt/problems/view/1173) | Lógica de progressão e preenchimento. | ✅  |
| **1174** | [Seleção em Vetor I](https://www.google.com/search?q=https://www.beecrowd.com.br/judge/pt/problems/view/1174) | Manipulação de tipos de ponto flutuante. | ✅  |
| **1175** | [Troca em Vetor I](https://www.google.com/search?q=https://www.beecrowd.com.br/judge/pt/problems/view/1175) | Lógica de inversão (Swap) e ponteiros. | ✅  |
| **1179** | [Preenchimento de Vetor IV](https://www.google.com/search?q=https://www.beecrowd.com.br/judge/pt/problems/view/1179) | Gerenciamento de múltiplos buffers. | ✅  |
| **1180** | [Menor e Posição](https://www.google.com/search?q=https://www.beecrowd.com.br/judge/pt/problems/view/1180) | Algoritmos de busca simples. | ✅  |
| **1171** | [Frequência de Números](https://www.google.com/search?q=https://www.beecrowd.com.br/judge/pt/problems/view/1171) | Vetores como contadores (Frequência). | ✅  |

-----

