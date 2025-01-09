/**
 * \file conta_palavras.cpp
 * \brief Implementação das funções para contagem e ordenação das palavras do texto.
 * \author Ana Luísa de Souza Paraguassu - 231003442.
 */

#include "conta_palavras.hpp"
#include <vector>
#include <utility>
#include <string>

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

std::vector<std::pair<std::string, int>>
ContaPalavras(const std::string& texto) {
  std::string lower_texto = lowerCase(texto);

  std::vector<std::pair<std::string, int>> palavras;

  separarEContar(lower_texto, palavras);

  return palavras;
}
