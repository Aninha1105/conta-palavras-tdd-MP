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
  std::string texto = "";
  auto resultado = ContaPalavras(texto);
  REQUIRE(resultado.size() == 0);
}
