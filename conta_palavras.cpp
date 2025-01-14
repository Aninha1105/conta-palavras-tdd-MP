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
#include <locale>
#include <codecvt>

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

std::string removerAcentos(std::string palavra) {
  std::vector<std::pair<std::string, std::string>> tabelaAcentos = {
        {"á", "a"}, {"à", "a"}, {"â", "a"}, {"ã", "a"},
        {"é", "e"}, {"è", "e"}, {"ê", "e"},
        {"í", "i"}, {"ì", "i"}, {"î", "i"},
        {"ó", "o"}, {"ò", "o"}, {"ô", "o"}, {"õ", "o"},
        {"ú", "u"}, {"ù", "u"}, {"û", "u"},
        {"ç", "c"}
  };

  std::string palavra_sem_acento;

  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
  auto utf32Texto = converter.from_bytes(palavra);
  for (char32_t c : utf32Texto) {
    std::string utf8Char = converter.to_bytes(c);
    bool substituido = false;
    for (const auto& par : tabelaAcentos) {
      if (utf8Char == par.first) {
        palavra_sem_acento += par.second;
        substituido = true;
        break;
      }
    }
    if (!substituido) {
      palavra_sem_acento += utf8Char;
    }
  }

  return palavra_sem_acento;
}

void merge(std::vector<std::pair<std::string,int>>& vetor, size_t inicio, size_t meio, size_t fim){}

void mergeSort(std::vector<std::pair<std::string,int>>& vetor, size_t inicio, size_t fim){
  if(inicio < fim){
    int meio = (inicio + fim) / 2;
    mergeSort(vetor,inicio,meio);
    mergeSort(vetor,meio + 1,fim);
    merge(vetor,inicio,meio,fim);
  }
}

void ordenaPalavras(std::vector<std::pair<std::string,int>>& palavras){
  mergeSort(palavras, 0, palavras.size()-1);
}

std::vector<std::pair<std::string, int>> ContaPalavras(std::string texto) {
  std::vector<std::pair<std::string, int>> palavras;
  palavras = separarEContar(texto);
  return palavras;
}
