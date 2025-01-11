/**
 * \file conta_palavras.cpp
 * \brief Implementação das funções para contagem e ordenação das palavras do texto.
 * \author Ana Luísa de Souza Paraguassu - 231003442.
 */

#include "conta_palavras.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <locale>
#include <codecvt>

/**
 * \brief Printa o conteúdo de um vetor de pares (palavra, contagem).
 * \param palavras Vetor contendo pares de palavras e suas respectivas contagens.
 * \return void
 * \details Cada par é impresso no formato "palavra: contagem".
 */
void printarResultado(std::vector<std::pair<std::string, int>>& palavras) {
  for (auto& par : palavras) {
    std::cout << par.first << ": " << par.second << std::endl;
  }
  std::cout << std::endl;
}

/**
 * \brief Remove acentos de uma palavra.
 * \param palavra String com possíveis caracteres acentuados.
 * \return String sem caracteres acentuados.
 */
std::string removerAcento(std::string& palavra) {
  std::vector<std::pair<std::string, std::string>> tabelaAcentos = {
          {"á", "a"}, {"à", "a"}, {"â", "a"}, {"ã", "a"},
          {"é", "e"}, {"è", "e"}, {"ê", "e"},
          {"í", "i"}, {"ì", "i"}, {"î", "i"},
          {"ó", "o"}, {"ò", "o"}, {"ô", "o"}, {"õ", "o"},
          {"ú", "u"}, {"ù", "u"}, {"û", "u"},
          {"ç", "c"}
  };

  std::string resultado;
  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;

  auto utf32Texto = converter.from_bytes(palavra);

  for (char32_t c : utf32Texto) {
    std::string utf8Char = converter.to_bytes(c);
    bool substituido = false;
    for (const auto& par : tabelaAcentos) {
      if (utf8Char == par.first) {
        resultado += par.second;
        substituido = true;
        break;
      }
    }
    if (!substituido) {
      resultado += utf8Char;
    }
  }

  return resultado;
}


/**
 * \brief Função auxiliar do merge sort para mesclar dois subvetores.
 * \param vetor Vetor a ser ordenado.
 * \param inicio Índice inicial do primeiro subvetor.
 * \param meio Índice final do primeiro subvetor e início do segundo.
 * \param fim Índice final do segundo subvetor.
 * \return void
 * \details Mescla dois subvetores ordenados em um único vetor ordenado.
 */
void merge(std::vector<std::pair<std::string, int>>& vetor,
int inicio, int meio, int fim) {
  std::vector<std::pair<std::string, int>> temp(fim - inicio + 1);
  int i = inicio, j = meio + 1, k = 0;

  while (i <= meio && j <= fim) {
    if (removerAcento(vetor[i].first) <= removerAcento(vetor[j].first)) {
      temp[k++] = vetor[i++];
    } else {
      temp[k++] = vetor[j++];
    }
  }

  while (i <= meio) temp[k++] = vetor[i++];
  while (j <= fim) temp[k++] = vetor[j++];

  for (k = 0; k < temp.size(); k++) {
    vetor[inicio + k] = temp[k];
  }
}

/**
 * \brief Ordena um vetor de pares (palavra, contagem).
 * \param vetor Vetor a ser ordenado.
 * \param inicio Índice inicial do vetor.
 * \param fim Índice final do vetor.
 * \return void
 * \details Divide o vetor em partes menores e usa a função merge para ordenar.
 */
void mergeSort(std::vector<std::pair<std::string, int>>& vetor,
int inicio, int fim) {
  if (inicio < fim) {
    int meio = (inicio + fim) / 2;
    mergeSort(vetor, inicio, meio);
    mergeSort(vetor, meio + 1, fim);
    merge(vetor, inicio, meio, fim);
  }
}

/**
 * \brief Ordena o vetor de palavras e contagens.
 * \param palavras Vetor contendo pares de palavras e suas contagens.
 * \return void
 * \details Usa merge sort para ordenar as palavras em ordem alfabética.
 */
void ordenaPalavras(std::vector<std::pair<std::string, int>>& palavras) {
  mergeSort(palavras, 0, palavras.size()-1);
}

/**
 * \brief Converte uma string para letras minúsculas.
 * \param texto String a ser convertida.
 * \return String com todas as letras em minúsculas.
 * \details Usa a função `tolower` para converter cada caractere.
 */
std::string lowerCase(const std::string& texto) {
  std::string lower_texto = "";
  for (size_t i = 0; i < texto.size(); i++) {
    lower_texto += tolower(texto[i]);
  }
  return lower_texto;
}

/**
 * \brief Separa as palavras de uma string e conta suas ocorrências.
 * \param texto String de entrada contendo o texto.
 * \param palavras Vetor para armazenar as palavras e suas contagens.
 * \return void
 * \details Palavras são separadas por espaços ou quebras de linha.
 */
void separarEContar(const std::string& texto,
std::vector<std::pair<std::string, int>>& palavras) {
  std::string palavra_atual = "";
  for (char c : texto) {
    if (c == ' ' || c == '\n' || c == ',' || c == '.') {
      if (!palavra_atual.empty()) {
        bool encontrada = false;
        for (auto& par : palavras) {
          if (par.first == palavra_atual) {
            par.second++;
            encontrada = true;
            break;
          }
        }
        if (!encontrada) {
          palavras.push_back({palavra_atual, 1});
        }
        palavra_atual = "";
      }
    } else {
      palavra_atual += c;
    }
  }

  if (!palavra_atual.empty()) {
    bool encontrada = false;
    for (auto& par : palavras) {
      if (par.first == palavra_atual) {
        par.second++;
        encontrada = true;
        break;
      }
    }
    if (!encontrada) {
      palavras.push_back({palavra_atual, 1});
    }
  }
}

/**
 * \brief Conta as palavras em um texto.
 * \param texto String contendo o texto de entrada.
 * \return Vetor de pares com as palavras e suas contagens.
 * \details Converte o texto para minúsculas, separa e conta as palavras, ordena e printa o resultado.
 */
std::vector<std::pair<std::string, int>>
ContaPalavras(const std::string& texto) {
  std::string lower_texto = lowerCase(texto);

  std::vector<std::pair<std::string, int>> palavras;

  separarEContar(lower_texto, palavras);

  ordenaPalavras(palavras);

  printarResultado(palavras);

  return palavras;
}
