/**
 * \file conta_palavras.hpp
 * \brief Declaração das funções para o contador de palavras.
 * \author Ana Luísa de Souza Paraguassu - 231003442.
 */

#ifndef CONTA_PALAVRAS_HPP_
#define CONTA_PALAVRAS_HPP_

#include <vector>
#include <utility>
#include <string>

std::vector<std::pair<std::string, int>>
ContaPalavras(const std::string& texto);
void separarEContar(const std::string& texto,
std::vector<std::pair<std::string, int>>& palavras);
std::string lowerCase(const std::string& texto);
void ordenaPalavras(std::vector<std::pair<std::string, int>>& palavras);
void mergeSort(std::vector<std::pair<std::string, int>>& vetor,
int inicio, int fim);
void merge(std::vector<std::pair<std::string, int>>& vetor,
int inicio, int meio, int fim);

#endif  // CONTA_PALAVRAS_HPP_
