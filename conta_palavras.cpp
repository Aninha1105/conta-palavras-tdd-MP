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

std::vector<std::pair<std::string,int>> separarEContar(std::string texto){
  return {};
}

std::vector<std::pair<std::string, int>> ContaPalavras(std::string texto) {
  std::vector<std::pair<std::string, int>> palavras;
  palavras = separarEContar(texto);
  return palavras;
}
