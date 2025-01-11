/**
 * \file conta_palavras.cpp
 * \brief Implementação das funções para contagem e ordenação das palavras do texto.
 * \author Ana Luísa de Souza Paraguassu - 231003442.
 */

#include "conta_palavras.hpp"
#include <vector>
#include <utility>
#include <string>
#include <locale>
#include <codecvt>

std::string lowerCase(const std::string& texto) {
  std::string lower_texto = "";
  for (size_t i = 0; i < texto.size(); i++) {
    lower_texto += tolower(texto[i]);
  }
  return lower_texto;
}

void separarEContar(const std::string& texto,
std::vector<std::pair<std::string, int>>& palavras) {
  std::string palavra_atual = "";
  for (char c : texto) {
    if (c == ' ' || c == '\n') {
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

std::string removerAcento(std::string& palavra){
 std::vector<std::pair<std::string,std::string>> tabelaAcentos = {
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

void mergeSort(std::vector<std::pair<std::string, int>>& vetor,
int inicio, int fim) {
  if (inicio < fim) {
    int meio = (inicio + fim) / 2;
    mergeSort(vetor, inicio, meio);
    mergeSort(vetor, meio + 1, fim);
    merge(vetor, inicio, meio, fim);
  }
}

void ordenaPalavras(std::vector<std::pair<std::string, int>>& palavras) {
  mergeSort(palavras, 0, palavras.size()-1);
}

std::vector<std::pair<std::string, int>>
ContaPalavras(const std::string& texto) {
  std::string lower_texto = lowerCase(texto);

  std::vector<std::pair<std::string, int>> palavras;

  separarEContar(lower_texto, palavras);

  ordenaPalavras(palavras);

  return palavras;
}
