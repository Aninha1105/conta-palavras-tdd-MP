# Contador de Palavras
Este projeto implementa um **contador de palavras** que processa um texto, normaliza as palavras (transformando-as em letras minúsculas e removendo acentos) e as organiza em ordem alfabética. Ele também conta a frequência de cada palavra no texto de entrada, utilizando a abordagem de **Desenvolvimento Orientado a Testes (TDD)**.

## Tecnologias Utilizadas
- **Linguagem:** C++
- **Framework de Testes:** [Catch2](https://github.com/catchorg/Catch2)
- **Ferramentas de Análise:**
  - `cpplint`: Para verificar o estilo de código.
  - `cppcheck`: Para análise estática do código.
  - `Valgrind`: Para detecção de vazamentos de memória.
  - `gcov`: Para análise de cobertura de testes.

## Funcionalidades
O programa executa as seguintes tarefas:

- **Transformar em Minúsculas:** Converte todas as letras do texto para minúsculas.
- **Remover Acentos:** Substitui caracteres acentuados por suas versões não acentuadas (ex.: "á" para "a").
- **Contar Palavras:** Separa e conta a frequência de cada palavra no texto.
- **Ordenar Palavras:** Ordena as palavras em ordem alfabética, ignorando acentos.
- **Imprimir Resultado:** Exibe as palavras e suas respectivas frequências.

## Como Executar

### 1. Clonar o Repositório

```bash
git clone https://github.com/Aninha1105/conta-palavras-tdd-MP.git 
cd conta-palavras-tdd-MP
```

### 2. Compilar e Executar o Projeto

```bash
make
```

## Conclusão
Este projeto demonstra a aplicação de TDD para construir um contador de palavras eficiente e confiável. A integração de boas práticas de programação e ferramentas de análise garante que o código seja fácil de manter e proporciona maior confiança no desenvolvimento das funcionalidades.

## Link para o GitHub
https://github.com/Aninha1105/conta-palavras-tdd-MP
