/**
 * \file conta_palavras.cpp
 * \brief Implementação das funções para contagem e ordenação das palavras do texto.
 * \author Ana Luísa de Souza Paraguassu - 231003442.
 */
#include "conta_palavras.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

std::string lerArquivo(std::string nome_do_arquivo) {
  std::ifstream arquivo("input/" + nome_do_arquivo);
  if (!arquivo.is_open()) {
    throw std::runtime_error("Erro ao abrir o arquivo: " + nome_do_arquivo);
  }
  std::ostringstream buffer;
  buffer << arquivo.rdbuf();
  return buffer.str();
}

std::vector<std::pair<std::string, int>> separarEContar(std::string texto) {
  std::vector<std::pair<std::string, int>> dicionario;
  std::string palavra_atual = "";
  for (char c : texto) {
    if (c == ' ' || c == '\n' || c == '.' || c == ',' || c == ':' ||
        c == ';' || c == '!' || c == '?' || c == '(' || c == ')' ||
        c == '=' || c == '*' || c == '#' || c == '&') {
      if (!palavra_atual.empty()) {
        bool encontrada = false;
        for (auto& par : dicionario) {
          if (par.first == palavra_atual) {
            par.second++;
            encontrada = true;
            break;
          }
        }
        if (!encontrada) {
          dicionario.push_back({palavra_atual, 1});
        }
        palavra_atual = "";
      }
    } else {
      palavra_atual += c;
    }
  }

  if (!palavra_atual.empty()) {
    bool encontrada = false;
    for (auto& par : dicionario) {
      if (par.first == palavra_atual) {
        par.second++;
        encontrada = true;
        break;
      }
    }
    if (!encontrada) {
      dicionario.push_back({palavra_atual, 1});
    }
  }

  return dicionario;
}

std::string lowerCase(std::string palavra) {
  std::string lower_palavra = "";
  for (size_t i = 0; i < palavra.size(); i++) {
    lower_palavra += tolower(palavra[i]);
  }
  return lower_palavra;
}

std::string removerAcentos(std::string palavra){
  return "";
}

std::vector<std::pair<std::string, int>> ContaPalavras(std::string texto) {
  std::vector<std::pair<std::string, int>> palavras;
  palavras = separarEContar(texto);
  return palavras;
}
