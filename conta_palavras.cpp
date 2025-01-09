/**
 * \file conta_palavras.cpp
 * \brief Implementação das funções para contagem e ordenação das palavras do texto.
 * \author Ana Luísa de Souza Paraguassu - 231003442.
 */

#include "conta_palavras.hpp"
#include <vector>
#include <utility>
#include <string>

void separarEContar(const std::string& texto, std::vector<std::pair<std::string,int>>& palavras){
 std::string palavra_atual = "";
 for(char c : texto){
  if(c == ' ' || c == '\n'){
    if(!palavra_atual.empty()){
      palavras.push_back({palavra_atual,1}); 
      palavra_atual = "" ;
    }
  } else{
    palavra_atual+=c;
  }
 }

 if(!palavra_atual.empty()){
  palavras.push_back({palavra_atual,1});
 }

}

std::vector<std::pair<std::string, int>> ContaPalavras(const std::string& texto) {
  std::vector<std::pair<std::string,int>> palavras;

   separarEContar(texto, palavras);
   
  return palavras;
}
