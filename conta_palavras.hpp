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

/**
 * \brief Função principal que conta as palavras em um texto.
 * \param texto String contendo o texto de entrada.
 * \return Vetor de pares com as palavras e suas contagens.
 */
std::vector<std::pair<std::string, int>>
ContaPalavras(const std::string& texto);

/**
 * \brief Separa as palavras de uma string e conta suas ocorrências.
 * \param texto String de entrada contendo o texto.
 * \param palavras Vetor para armazenar as palavras e suas contagens.
 * \return void
 */
void separarEContar(const std::string& texto,
std::vector<std::pair<std::string, int>>& palavras);

/**
 * \brief Converte uma string para letras minúsculas.
 * \param texto String a ser convertida.
 * \return String com todas as letras em minúsculas.
 */
std::string lowerCase(const std::string& texto);

/**
 * \brief Ordena o vetor de palavras e contagens.
 * \param palavras Vetor contendo pares de palavras e suas contagens.
 * \return void
 */
void ordenaPalavras(std::vector<std::pair<std::string, int>>& palavras);

/**
 * \brief Ordena um vetor de pares (palavra, contagem).
 * \param vetor Vetor a ser ordenado.
 * \param inicio Índice inicial do vetor.
 * \param fim Índice final do vetor.
 * \return void
 */
void mergeSort(std::vector<std::pair<std::string, int>>& vetor,
int inicio, int fim);

/**
 * \brief Função auxiliar do merge sort para mesclar dois subvetores.
 * \param vetor Vetor a ser ordenado.
 * \param inicio Índice inicial do primeiro subvetor.
 * \param meio Índice final do primeiro subvetor e início do segundo.
 * \param fim Índice final do segundo subvetor.
 * \return void
 */
void merge(std::vector<std::pair<std::string, int>>& vetor,
int inicio, int meio, int fim);

/**
 * \brief Remove acentos de uma palavra.
 * \param palavra String com possíveis caracteres acentuados.
 * \return String sem caracteres acentuados.
 */
std::string removerAcento(std::string& palavra);

/**
 * \brief Printa o conteúdo de um vetor de pares (palavra, contagem).
 * \param palavras Vetor contendo pares de palavras e suas respectivas contagens.
 * \return void
 */
void printarResultado(std::vector<std::pair<std::string, int>>& palavras);

#endif  // CONTA_PALAVRAS_HPP_
