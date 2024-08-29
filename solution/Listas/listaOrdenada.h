#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include "lista.h"
#include "../Termo/termo.h"
#include <algorithm>

/*
  Classe ListaOrdenada: filha da classe Lista, possui métodos de ordenação.
*/

template <typename T> class ListaOrdenada : public Lista<T> {
public:
  // Sort padrão do STL
  void sortSTL();
  // Bubblesort implementado
  void sortCompare();
};

template <typename T> void ListaOrdenada<T>::sortSTL() {
  // Método de ordenação padrão do STL
  std::sort(this->list, this->list + this->size);
}

template <typename T> void ListaOrdenada<T>::sortCompare() {
  // Bubblesort implementado, utilizando a função de comparação para generalizar
  // o algoritmo
  for (int i = 0; i < this->size - 1; i++) {
    for (int j = i + 1; j < this->size; j++) {
      if (compare(this->list[i], this->list[j]) > 0) {
        T aux = this->list[i];
        this->list[i] = this->list[j];
        this->list[j] = aux;
      }
    }
  }
}

#endif