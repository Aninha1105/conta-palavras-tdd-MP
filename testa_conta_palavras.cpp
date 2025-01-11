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

TEST_CASE("Teste 1: ContaPalavras retorna vazio para texto vazio") {
    std::string texto = "";
    auto resultado = ContaPalavras(texto);

    REQUIRE(resultado.empty());
}

TEST_CASE("Teste 2: Separação de palavras") {
  std::string texto = "exemplo de texto";
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 3);
  REQUIRE(resultado[1].first == "exemplo");
  REQUIRE(resultado[0].first == "de");
  REQUIRE(resultado[2].first == "texto");
}

TEST_CASE("Teste 3: Contar corrências de palavras repetidas") {
  std::string texto = "este teste e um exemplo de um teste";
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 6);
  REQUIRE(resultado[4].first == "teste");
  REQUIRE(resultado[4].second == 2);
  REQUIRE(resultado[5].first == "um");
  REQUIRE(resultado[5].second == 2);
}

TEST_CASE("Teste 4: Converter todas as palavras para lowercase") {
  std::string texto = "texto TexTO TEXTO";
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 1);
  REQUIRE(resultado[0].first == "texto");
  REQUIRE(resultado[0].second == 3);
}

TEST_CASE("Teste 5: Ordenação alfabética das palavras") {
  std::string texto = "Este exemplo de teste serve para ordenar palavras";
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 8);
  REQUIRE(resultado[0].first == "de");
  REQUIRE(resultado[1].first == "este");
  REQUIRE(resultado[2].first == "exemplo");
  REQUIRE(resultado[3].first == "ordenar");
  REQUIRE(resultado[4].first == "palavras");
  REQUIRE(resultado[5].first == "para");
  REQUIRE(resultado[6].first == "serve");
  REQUIRE(resultado[7].first == "teste");
}

TEST_CASE("Teste 6: Ordenação considerando acentos") {
  std::string texto = "Este texto é o texto padrão";
  auto resultado = ContaPalavras(texto);

  REQUIRE(resultado.size() == 5);
  REQUIRE(resultado[0].first == "é");
  REQUIRE(resultado[1].first == "este");
  REQUIRE(resultado[2].first == "o");
  REQUIRE(resultado[3].first == "padrão");
  REQUIRE(resultado[4].first == "texto");
}
