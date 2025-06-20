
# Trabalho Final - Algoritmos e Estruturas de Dados I

![Universidade Federal de Goiás](https://img.shields.io/badge/UFG-Instituto%20de%20Informática-blue)
![Linguagem C](https://img.shields.io/badge/Linguagem-C-blue)
![Estrutura de Dados](https://img.shields.io/badge/Estrutura-Lista%20Duplamente%20Encadeada%20com%20Nó%20Descritor-green)
![Método Simples - Selection Sort](https://img.shields.io/badge/Método%20Simples-Selection%20Sort-orange)
![Método Avançado - Quick Sort](https://img.shields.io/badge/Método%20Avançado-Quick%20Sort-purple)

---

## Descrição

Este projeto implementa e compara o desempenho de dois algoritmos de ordenação:

- **Selection Sort** (método simples)  
- **Quick Sort** (método avançado)

As implementações foram desenvolvidas utilizando a estrutura de **Lista Linear Duplamente Encadeada com Nó Descritor**, seguindo a abordagem de **Tipos Abstratos de Dados (TAD)**.

O trabalho foi desenvolvido como parte da disciplina **Algoritmos e Estruturas de Dados I**, na **Universidade Federal de Goiás (UFG)**, com o objetivo de:

- Praticar conceitos de estruturas de dados dinâmicas.
- Analisar empiricamente e matematicamente algoritmos de ordenação.
- Desenvolver habilidades de trabalho em equipe, versionamento de código e documentação técnica.

---

## Pré-requisitos

- Compilador C (`gcc` ou compatível)
- Terminal de comando (Linux, macOS ou Windows com WSL)

---

## Funcionalidades

- Criação e destruição da lista
- Inserção no início, fim e meio
- Remoção no início, fim e meio
- Leitura e gravação de arquivos
- Ordenação:
  - Selection Sort (Crescente e Decrescente)
  - Quick Sort (Crescente e Decrescente)
- Contagem de swaps (trocas realizadas)
- Medição de tempo de execução


---

## Instruções de Instalação

### Clone este repositório:

```bash
git clone https://github.com/seu-usuario/seu-repositorio.git
cd seu-repositorio
````

### Compile o programa:

```bash
gcc main.c lista.c -o nome_programa_compilado
```
---
## Instruções de Uso:

### Entrada esperada:
- Arquivo texto (.in) com dados:
  - Cada linha contendo um número inteiro ou uma string (dependendo da versão que você está utilizando).

- O nome do arquivo deve estar indicado no main.c dentro da função:

```bash
listaLerArquivos(minha_lista, "aleatorios_1.in");
````

Modifique `aleatorios_1.i` pelo nome do seu arquivo de entrada.

### Para executar:

```bash
./programa
```

### Escolha da ordenação:

Dentro do main.c, descomente o algoritmo desejado:

```c
//listaSelectionSortCrescente(minha_lista);
//listaSelectionSortDecrescente(minha_lista);
//listaQuickSortCrescente(minha_lista);
//listaQuickSortDecrescente(minha_lista);
````

### Saída gerada:

Um arquivo chamado `arquivo_resultado.out` contendo os dados ordenados (um por linha).

No terminal, será exibido:

- Tempo de execução

- Quantidade de swaps (trocas realizadas)

---
## Casos de Teste, Exemplos de Entrada e Saída:

OBSERVAÇÃO: Nos tempos, o ponto representa vírgula decimal. Nos swaps, o ponto serve apenas para separar visualmente os valores (não é decimal).

### Exemplo de arquivo de entrada:

### Para números:

```bash
58689
50677
52675
64512
74743
80365
80249
70542
13415
````


### Para nomes:
```bash
adamir_mader
adonis_zimmermann
adison_s_mon_teiro_dilson
adrian_ribeiro
adelson_macharet
adriano_pedreiro_reformas
````

### Exemplo de saída ordenada (crescente):

### Para números:

```bash
1557
13415
50677
52675
58689
64512
70542
74743
80249
80365
```

### Para nomes:

```bash
adamir_mader
adelson_macharet
adison_s_mon_teiro_dilson
adonis_zimmermann
adrian_ribeiro
adriano_pedreiro_reformas
````

*Observação:* O código permite tanto trabalhar com listas de números quanto com listas de nomes, dependendo da versão de lista.c e lista.h que você utilizar:

- Versão 1: Números (int)
- Versão 2: Nomes (char*)

A escolha do algoritmo de ordenação (Selection ou Quick, crescente ou decrescente) é feita diretamente no main.c descomentando a linha desejada.
O nome do arquivo de entrada é alterado diretamente no parâmetro da função:

```c
listaLerArquivos(minha_lista, "nome_do_arquivo.in");
````
---
## Estrutura de Arquivos:

```bash
├──lista_nomes
  ├── lista.h               # Arquivo de cabeçalho (declaração das funções e structs)
  ├── lista.c               # Implementação da TAD Lista Duplamente Encadeada
  ├── main.c                # Arquivo principal com execução dos testes
  ├── arquivo_entrada.in    # Arquivo de entrada com dados
  ├── arquivo_resultado.out # Arquivo de saída com dados ordenados

├──lista_numeros
  ├── lista.h               # Arquivo de cabeçalho (declaração das funções e structs)
  ├── lista.c               # Implementação da TAD Lista Duplamente Encadeada
  ├── main.c                # Arquivo principal com execução dos testes
  ├── arquivo_entrada.in    # Arquivo de entrada com dados
  ├── arquivo_resultado.out # Arquivo de saída com dados ordenados

├──vetor_nomes
  ├── vetor.c        # Implementação usando vetor de strings
  ├── arquivo_entrada.in    # Arquivo de entrada com dados
  ├── arquivo_resultado.out # Arquivo de saída com dados ordenados

├──vetor_numeros
  ├── vetor.c        # Implementação usando vetor de números inteiros
  ├── arquivo_entrada.in    # Arquivo de entrada com dados
  ├── arquivo_resultado.out # Arquivo de saída com dados ordenados

````


---
## Licença Educacional

Este projeto foi desenvolvido exclusivamente para fins educacionais no contexto da disciplina Algoritmos e Estruturas de Dados I — Universidade Federal de Goiás (UFG). Uso restrito ao ambiente acadêmico.

---


## Contribuidores

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/fragaeduardo">
        <img src="Fotos/Eduardo.jpeg" width="100px;" alt="Eduardo Fraga"/><br />
        <sub><b>Eduardo Fraga</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/elunzhang">
        <img src="Fotos/Elun.jpeg" width="100px;" alt="Elun Zhang"/><br />
        <sub><b>Elun Zhang</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/estherfbastos">
        <img src="Fotos/Esther.jpeg" width="100px;" alt="Esther Bastos"/><br />
        <sub><b>Esther Bastos</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/BrunnoBernardes">
        <img src="Fotos/Bruno.jpeg" width="100px;" alt="Brunno Bernardes"/><br />
        <sub><b>Brunno Bernardes</b></sub>
      </a>
    </td>
  </tr>
</table>

---
