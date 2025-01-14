/**
 * \file testa_conta_palavras.cpp
 * \brief Testes unitários para verificar o contador de palavras usando Catch2.
 * \author Ana Luísa de Souza Paraguassu - 231003442
 */

#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "conta_palavras.hpp"
#include <string>

TEST_CASE("Teste 1: texto vazio") {
  std::string texto = lerArquivo("teste1");
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 0);
}

TEST_CASE("Teste 2: leitura de arquivo") {
  std::string texto = lerArquivo("teste2");
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 1);
}

TEST_CASE("Teste 3: separação de palavras") {
  std::string texto = lerArquivo("teste3");
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 2);
  REQUIRE(resultado[0].first == "texto");
  REQUIRE(resultado[1].first == "utilizado");
}

TEST_CASE("Teste 4: contagem de ocorrências das palavras") {
  std::string texto = lerArquivo("teste4");
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 3);
  REQUIRE(resultado[0].first == "texto");
  REQUIRE(resultado[0].second == 2);
  REQUIRE(resultado[1].first == "utilizado");
  REQUIRE(resultado[1].second == 1);
  REQUIRE(resultado[2].first == "validado");
  REQUIRE(resultado[2].second == 1);
}
