#ifndef LISTA_H
#define LISTA_H

#include "../Functions/funcs.h"
#include <iostream>

using namespace std;

/*
  Classe Lista: uma lista de tipo de dados genérico, utilizando ponteiro para um
  array.
*/

template <typename T> class Lista {
protected:
  // Size = Tamanho atual da lista
  int size;
  // Capacity = Capacidade máxima de elementos que podem ser armazenados na
  // lista
  int capacity;
  // List = Ponteiro para um array de elementos do tipo T (genérico)
  T *list = nullptr;

public:
  // Construtor padrão
  Lista();
  // Destrutor
  ~Lista();

  // Método que adiciona um elemento no final da lista
  void add(T data);
  // Método que remove um elemento no índice desejado
  void deleteByIndex(int index);
  // Método que retorna o tamanho da lista
  int getSize();
  // Método que imprime os itens da lista
  void print(int qnt = -1);
  // Sobrecarga do operador "[]", utilizado para acessar elementos específicos
  // pelo seu índice
  T &operator[](int index);
};

template <typename T> Lista<T>::Lista() {
  // Construtor inicia os atributos da classe, definindo o tamanho da lista como
  // 0 e a capacidade como 10
  size = 0;
  capacity = 10;
  // Aloca dinamicamente um array de tamanho 10 do tipo T
  list = new T[capacity];
}

template <typename T> Lista<T>::~Lista() {
  // Destrutor libera a memória alocada para o array
  delete[] list;
}

template <typename T> void Lista<T>::add(T data) {
  if (size == capacity) {
    // Se a lista estiver cheia, dobra a capacidade do array
    capacity *= 2;
    // Aloca um novo array que recebe uma cópia do array antigo, com a nova
    // capacidade
    T *tempList = new T[capacity];
    copyArray(list, tempList, size);
    // Libera a memória do array antigo, e atribui o novo array ao atributo list
    delete[] list;
    list = tempList;
  }
  // Adiciona o elemento no final da lista e incrementa o tamanho
  list[size] = data;
  size++;
}

template <typename T> void Lista<T>::deleteByIndex(int index) {
  // Verifica se o índice é válido
  if (index < 0 || index > size) {
    cout << "Índice inválido" << endl;
    return;
  }
  // Move todos os elementos a partir do índice para a esquerda, decrementando o
  // tamanho
  for (; index < size - 1; index++) {
    list[index] = list[index + 1];
  }
  size--;
}

template <typename T> int Lista<T>::getSize() {
  // Retorna o tamanho da lista
  return size;
}

template <typename T> void Lista<T>::print(int qnt) {
  // Checa se a quantidade de elementos foi passada como parâmetro
  if (qnt == -1 || qnt >= size) {
    // Caso a quantidade for -1 (padrão), ou a quantidade específicada for maior
    // que o tamanho da lista, imprime todos os elementos da lista
    for (int i = 0; i < size; i++) {
      cout << list[i] << endl;
    }
  } else {
    // Caso a quantidade tenha sido especificada e a quantidade for menor que o
    // tamanho da lista, imprime a quantidade de elementos desejada
    for (int i = 0; i < qnt; i++) {
      cout << list[i] << endl;
    }
  }
}

template <typename T> T &Lista<T>::operator[](int index) {
  // Verifica se o índice é válido
  if (index >= 0 && index < size) {
    // Caso seja retorna o elemento no índice especificado
    return list[index];
  } else {
    // Caso não seja, retorna um erro
    throw out_of_range("Índice inválido");
  }
}

#endif