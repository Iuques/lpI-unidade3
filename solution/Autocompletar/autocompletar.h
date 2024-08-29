#ifndef AUTOCOMPLETAR_H
#define AUTOCOMPLETAR_H

#include "../Listas/listaOrdenada.h"
#include "../Termo/termo.h"
#include <iostream>

using namespace std;

/*
  Classe Autocompletar: possúi métodos para realizar a busca de um prefixo em
  uma lista de termos.
*/

class Autocompletar {
private:
  // Método que busca individualmente um termo na lista de termos, utilizando a
  // busca binária
  Termo binarySearchPrefix(ListaOrdenada<Termo> &listaTermos, string prefix,
                           int inic, int fim);
  // Ordena uma lista de termos por peso, em ordem decrescente
  void sortByPeso(ListaOrdenada<Termo> &listaTermos);

public:
  // Construtor padrão
  Autocompletar();
  // Método de busca pelo prefixo, imprime uma lista de 'k' termos que possuem o
  // prefixo
  static void searchByPrefix(ListaOrdenada<Termo> &listaTermos, string prefix,
                             int k);
};

#endif