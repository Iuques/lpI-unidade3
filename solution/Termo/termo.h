#ifndef TERMO_H
#define TERMO_H

#include <iostream>
#include <string>

/*
  Definição da classe termo: uma palavra e um peso associado. Possui métodos de
  comparação para ordenação.
*/

using namespace std;

class Termo {
private:
  // atributo termo = palavra, atributo peso = inteiro do tipo long
  string termo;
  long peso;

public:
  // Construtor padrão
  Termo();
  // Construtor com parâmetros
  Termo(string termo_, long peso_);

  // Métodos de comparação por peso e por prefixo
  static int comparaPeloPeso(Termo t1, Termo t2);
  static int comparaPeloPrefixo(Termo t1, Termo t2, int r);

  // Método de comparação do prefixo de um termo com uma string (para a busca
  // binária)
  int comparaPrefixoComString(string s);

  // Checa se o peso do termo é válido (usado para parar o loop na busca
  // binária)
  bool isPesoValido();

  // Sobrecarga do operado "=", para ser possível trocar um termo por outro
  Termo &operator=(const Termo &other);
  // Sobrecarga do operado "==", compara as palavras (strings) dos termos
  bool operator==(Termo t);
  // Sobrecarga do operador "<", compara as palavras (strings) dos termos
  bool operator<(Termo t);
  // Sobrecarga do operador "<<", para imprimir os dados de um termo
  friend std::ostream &operator<<(std::ostream &out, const Termo &t);

  // Método que imprime os dados do termo (usado para testes)
  void printData();
  // Testes pros métodos de comparação (usado para testes)
  void testeCompPeso(Termo t);
  void testeCompPref(Termo t, int r);
};

#endif