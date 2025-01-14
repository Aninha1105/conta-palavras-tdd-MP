/**
 * \file conta_palavras.hpp
 * \brief Declaração das funções para o contador de palavras.
 * \author Ana Luísa de Souza Paraguassu - 231003442.
 */
#ifndef CONTA_PALAVRAS_HPP_
#define CONTA_PALAVRAS_HPP_

#include <string>
#include <vector>
#include <utility>

std::vector<std::pair<std::string, int>> ContaPalavras(std::string texto);
std::string lerArquivo(std::string nome_do_arquivo);
std::vector<std::pair<std::string, int>> separarEContar(std::string texto);
std::string lowerCase(std::string palavra);
std::string removerAcentos(std::string palavra);
void ordenaPalavras(std::vector<std::pair<std::string,int>>& palavras);

#endif  // CONTA_PALAVRAS_HPP_
