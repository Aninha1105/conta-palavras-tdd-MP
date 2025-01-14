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

/**
 * \brief Função principal que conta as palavras em um texto.
 * \param texto String contendo o texto de entrada.
 * \return Vetor de pares com as palavras e suas contagens.
 */
std::vector<std::pair<std::string, int>> ContaPalavras(std::string texto);

/**
 * \brief Lê o conteúdo de um arquivo e retorna como uma string.
 * \param nome_do_arquivo Nome do arquivo a ser lido.
 * \return Retorna o conteúdo do arquivo como uma string.
 */
std::string lerArquivo(std::string nome_do_arquivo);

/**
 * \brief Separa as palavras de uma string e conta suas ocorrências.
 * \param texto String de entrada contendo o texto.
 * \return Vetor com pares no formato (palavra, frequência).
 */
std::vector<std::pair<std::string, int>> separarEContar(std::string texto);

/**
 * \brief Converte uma string para letras minúsculas.
 * \param texto String a ser convertida.
 * \return String com todas as letras em minúsculas.
 */
std::string lowerCase(std::string palavra);

/**
 * \brief Remove acentos de uma palavra.
 * \param palavra String com possíveis caracteres acentuados.
 * \return String sem caracteres acentuados.
 */
std::string removerAcentos(std::string palavra);

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
 * \brief Ordena um vetor de pares (palavra, frequência).
 * \param vetor Vetor a ser ordenado.
 * \param inicio Índice inicial do vetor.
 * \param fim Índice final do vetor.
 * \return void
 */
void mergeSort(std::vector<std::pair<std::string, int>>& vetor,
               int inicio, int fim);

/**
 * \brief Ordena o vetor de palavras e frequências.
 * \param palavras Vetor contendo pares de palavras e suas frequências.
 * \return void
 */
void ordenaPalavras(std::vector<std::pair<std::string, int>>& palavras);

#endif  // CONTA_PALAVRAS_HPP_
