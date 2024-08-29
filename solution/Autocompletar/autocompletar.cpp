#include "autocompletar.h"

Autocompletar::Autocompletar() {}

// Implementação do método de busca
void Autocompletar::searchByPrefix(ListaOrdenada<Termo> &listaTermos,
                                   string prefix, int k) {
  // Cria uma instância de Autocompletar para ser possível chamar os outros
  // métodos
  Autocompletar autocompletarInstance;

  // Cria uma nova lista para armazenar os termos filtrados
  ListaOrdenada<Termo> listaFiltrada;

  // Loop que percorre a lista de termos
  while (true) {
    // Chama o método de busca binária e armazena o termo encontrado num objeto
    // do tipo Termo
    Termo termoEncontrado = autocompletarInstance.binarySearchPrefix(
        listaTermos, prefix, 0, listaTermos.getSize() - 1);

    // Checa se o termo encontrado é válido
    // isso é importante para saber quando todos os termos com o prefixo
    // desejado foram encontrados
    if (!termoEncontrado.isPesoValido()) {
      // Caso não seja, encerra o loop
      break;
    }

    // Adiciona o termo encontrado à lista filtrada
    listaFiltrada.add(termoEncontrado);
  }

  // Checa
  if (listaFiltrada.getSize() == 0){
    cout << "Nenhum termo encontrado" << endl;
    return;
  }

  // Chama o método de ordenação da lista por peso
  autocompletarInstance.sortByPeso(listaFiltrada);

  // Imprime os primeiros 'k' termos filtrados
  cout << "Termos encontrados com o prefixo " << prefix << ": " << endl;
  listaFiltrada.print(k);
}

// Implementação da busca binária
Termo Autocompletar::binarySearchPrefix(ListaOrdenada<Termo> &listaTermos,
                                        string prefix, int inic, int fim) {
  // Calcula o índice do meio da lista
  int meio = (inic + fim) / 2;
  // Checa se toda a lista já foi percorrida, caso o inicio seja maior que o
  // fim, significa que a recursão chegou ao fim
  if (inic > fim) {
    // Caso a lista tenha sido percorrida, retorna um termo inválido (Com peso
    // -1)
    return Termo("NULL", -1);
  }

  // Checa se o termo no meio da lista é igual ao prefixo desejado
  if (listaTermos[meio].comparaPrefixoComString(prefix) == 0) {
    // Caso seja, armazena o termo numa variável temporária
    Termo termoEncotrado = listaTermos[meio];
    // Deleta o termo encontrado da lista (para quando o algorítmo for chamado
    // novamente, o termo não se repetir)
    listaTermos.deleteByIndex(meio);
    // Retorna o termo encontrado
    return termoEncotrado;
  }
  // Checa se o termo no meio da lista é maior que o prefixo desejado
  if (listaTermos[meio].comparaPrefixoComString(prefix) == 1) {
    // Caso seja, chama a recursão passando só a metade esquerda da lista
    return binarySearchPrefix(listaTermos, prefix, inic, meio - 1);
  }
  // Checa se o termo no meio da lista é menor que o prefixo desejado
  if (listaTermos[meio].comparaPrefixoComString(prefix) == -1) {
    // Caso seja, chama a recursão passando só a metade direita da lista
    return binarySearchPrefix(listaTermos, prefix, meio + 1, fim);
  }

  // Checa se o prefixo tem tamanho maior que o termo no meio da lista
  if (listaTermos[meio].comparaPrefixoComString(prefix) == 2) {
    // Caso seja, chama a recursão aumentando o início em 1 unidade
    return binarySearchPrefix(listaTermos, prefix, inic + 1, fim);
  }

  // Caso todos os testes falhem, retorna um termo inválido
  return Termo("NULL", -1);
}

// Implementação do método de ordenação por peso
void Autocompletar::sortByPeso(ListaOrdenada<Termo> &listaTermos) {
  // Pega o tamanho da lista
  int n = listaTermos.getSize();

  // Bubblesort para ordenar a lista, usando o método estático 'comparaPeloPeso'
  // da classe Termo
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      // Como a ordenação é decrescente, a checagem é inversa
      if (Termo::comparaPeloPeso(listaTermos[i], listaTermos[j]) < 0) {
        Termo temp = listaTermos[i];
        listaTermos[i] = listaTermos[j];
        listaTermos[j] = temp;
      }
    }
  }
}
