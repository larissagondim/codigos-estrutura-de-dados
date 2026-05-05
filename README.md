# Códigos - Estrutura de Dados

Repositório com códigos desenvolvidos durante meu aprendizado na disciplina de **Estrutura de Dados e Algoritmos** na **UFPB (Universidade Federal da Paraíba)**.

Os exercícios aqui presentes são provenientes de:

* atividades realizadas pós sala de aula
* listas propostas pelo professor
* exercícios do livro *“Introdução a Estruturas de Dados”* de Waldemar Celes, Renato Cerqueira e José Lucas Rangel (e materiais complementares)

O objetivo deste repositório é servir como apoio aos estudos, prática de programação e consolidação dos conceitos fundamentais da disciplina.

---

## Organização do Repositório

Os códigos estão organizados por aulas e exercícios. Cada pasta representa um problema ou tema específico.

| Pasta                   | Descrição                                        |
| ----------------------- | ------------------------------------------------ |
| `aula1/tabela-ascii`    | Programa que imprime a tabela ASCII         |
| `aula2/eh_primo`        | Verificação de número primo                      |
| `aula2/esfera` | Calcula a área e o volume de uma esfera |
| `aula2/fibonacci`       | Cálculo do n-ésimo termo da sequência de Fibonacci                |
| `aula2/leibniz` | Utiliza da fórmula de Leibniz com N fatores para calcular uma aproximação de pi |
| `aula2/ponto_retangulo` | Verifica se um ponto está dentro de um retângulo |
| `aula2/raízes equação` | Calcula as raízes de uma equação do segundo grau com passagem de parâmetros por referência |
| `aula2/soma_impares` | Soma os números ímpares de 1 até 'n'|
| `aula3/nome_idade` | Lê nomes e idades de 'n' pessoas e salva em um txt |
| `aula3/maior_18` | Mostra nome de pessoas maiores de 18 anos em um txt |
---

## Estrutura dos Códigos

Cada exercício segue um padrão de organização em múltiplos arquivos:

* `main.c`
  Responsável pela execução principal do programa (função `main`), entrada e saída de dados.

* `<modulo>.c`
  Contém a implementação das funções principais do exercício.

* `<modulo>.h`
  Header file que declara, de maneira bem documentada, as funções utilizadas no módulo. Permite separação entre interface e implementação.


---

### Exemplo de organização

```bash
fibonacci/
├── main.c
├── fibonacci.c
├── fibonacci.h
```

* `fibonacci.h` → declaração da função `fibonacci`
* `fibonacci.c` → implementação da lógica
* `main.c` → chama a função e mostra o resultado

---

## Conteúdo

Os códigos abordam temas como:

* vetores e matrizes
* listas (simples, duplamente encadeadas)
* pilhas e filas
* recursão
* algoritmos clássicos (busca, ordenação, etc.)

---

## Progresso

* [x] Conceitos básicos de C
* [ ] Vetores e matrizes
* [x] Arquivos
* [ ] Funções e recursão
* [X] Ponteiros
* [ ] Alocação dinâmica de memória
* [ ] Listas encadeadas
* [ ] Pilhas
* [ ] Filas
* [ ] Árvores
* [ ] Algoritmos de ordenação avançados
* [ ] Grafos

> *Obs: esta lista será atualizada conforme avanço na disciplina.*

---

## Observação

Os códigos podem sofrer melhorias e refatorações ao longo do tempo conforme avanço na disciplina.
