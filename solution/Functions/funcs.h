#ifndef FUNCS_H
#define FUNCS_H

#include "../Termo/termo.h"
#include <iostream>

using namespace std;

// Definição das funções auxiliares

// Função para comparar valores (usada na ordenação de uma lista)
template <typename T> int compare(T n1, T n2) {
  // Checa se o valor anterior é maior que o posterior
  if (n1 < n2) {
    // Retorna 1 caso maior
    return -1;
  } else if (n1 == n2) {
    // Retorna 0 caso igual
    return 0;
  } else {
    // Retorna -1 caso menor
    return 1;
  }
}

// Função que copia um array para outro (usada ao adicionar elementos na lista)
template <typename T> void copyArray(T *oldArray, T *newArray, int oldSize) {
  // Copia os elementos do array antigo para o novo
  for (int i = 0; i < oldSize; i++) {
    newArray[i] = oldArray[i];
  }
}

#endif