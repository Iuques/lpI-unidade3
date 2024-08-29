#include "tests.h"

void testaLista() {
  ListaOrdenada<int> lista;

  cout << "Testando metódos da classe mãe Lista --------------" << endl;
  lista.add(7);
  lista.add(5);
  lista.add(6);
  lista.add(8);
  lista.add(9);
  cout << "Tamanho: " << lista.getSize() << endl;
  cout << "Lista impressa: " << endl;
  lista.print();
  cout << "Elemento no índice 2: " << lista[2] << endl;
  cout << "Adicionando mais dois elementos" << endl;
  lista.add(1);
  lista.add(3);
  cout << "Lista impressa: " << endl;
  lista.print();
  cout << "Novo tamanho: " << lista.getSize() << endl;

  cout << "Testando metódos da classe ListaOrdenada --------------" << endl;
  lista.sortSTL();
  cout << "Lista após a ordenação (STL): " << endl;
  lista.print();
  cout << "Elemento no índice 2: " << lista[2] << endl;
  cout << "Adicionando mais três elementos" << endl;
  lista.add(2);
  lista.add(4);
  lista.add(0);
  cout << "Novo tamanho: " << lista.getSize() << endl;
  cout << "Lista impressa: " << endl;
  lista.print();
  cout << "Elemento no índice 3: " << lista[3] << endl;
  lista.sortCompare();
  cout << "Lista após a ordenação (bubblesort implementado): " << endl;
  lista.print();
  cout << "Elemento no índice 3: " << lista[3] << endl;

  cout << "Testando adicionar elementos além da capacidade máxima -------------"
       << endl;
  cout << "Adicionando mais 5 elementos" << endl;
  lista.add(10);
  lista.add(12);
  lista.add(11);
  lista.add(13);
  lista.add(14);
  cout << "Novo tamanho: " << lista.getSize() << endl;
  cout << "Lista impressa: " << endl;
  lista.print();
  lista.sortSTL();
  cout << "Deletando o elemento no índice 0." << endl;
  lista.deleteByIndex(0);
  cout << "Lista ordenada: " << endl;
  lista.print();
}

void testaTermo() {
  Termo termo1("Abacate", 10);
  Termo termo2("Abacaxi", 15);
  Termo termo3("Banana", 20);
  cout << "Termo1: ";
  termo1.printData();
  cout << "Termo2: ";
  termo2.printData();
  cout << "Termo3: ";
  termo3.printData();

  cout << "Comparando termo1 com termo2 -----" << endl;
  cout << "Resultado comparando pelo peso: ";
  termo1.testeCompPeso(termo2);
  cout << "Resultado comparando pelo prefixo com 5 caracteres: ";
  termo1.testeCompPref(termo2, 5);
  cout << "Resultado comparando pelo prefixo com 7 caracteres: ";
  termo1.testeCompPref(termo2, 7);
  if (termo1 < termo2) {
    cout << "Resultado sobrecarga do operador <: Termo1 vem antes de Termo2"
         << endl;
  } else {
    cout << "Resultado sobrecarga do operador <: Termo2 vem antes de Termo1"
         << endl;
  }

  cout << "Comparando termo1 com termo3 -----" << endl;
  cout << "Resultado comparando pelo peso: ";
  termo1.testeCompPeso(termo3);
  cout << "Resultado comparando pelo prefixo com 5 caracteres: ";
  termo1.testeCompPref(termo3, 5);
  if (termo1 < termo3) {
    cout << "Resultado sobrecarga do operador <: Termo1 vem antes de Termo3"
         << endl;
  } else {
    cout << "Resultado sobrecarga do operador <: Termo3 vem antes de Termo1"
         << endl;
  }

  cout << "Comparando termo2 com termo3 -----" << endl;
  cout << "Resultado comparando pelo peso: ";
  termo2.testeCompPeso(termo3);
  cout << "Resultado comparando pelo prefixo com 5 caracteres: ";
  termo2.testeCompPref(termo3, 5);
  if (termo2 < termo3) {
    cout << "Resultado sobrecarga do operador <: Termo2 vem antes de Termo3"
         << endl;
  } else {
    cout << "Resultado sobrecarga do operador <: Termo3 vem antes de Termo2"
         << endl;
  }
}

void testaListaTermos() {
  cout << "Lista 1: " << endl;
  ifstream dataSet("datasets/actors.txt");
  if (dataSet.bad()) {
    cerr << "Não foi possível abrir o arquivo." << endl;
    return;
  }

  int i = 0;
  ListaOrdenada<Termo> lista;
  while (i < 8) {
    string peso;
    string termo;

    while (dataSet.peek() == ' ') {
      dataSet.ignore(1);
    };

    getline(dataSet, peso, '\t');
    long pesoLong = stol(peso);

    getline(dataSet, termo, '\n');
    Termo termoObj(termo, pesoLong);

    lista.add(termoObj);

    i++;
  }
  dataSet.close();

  cout << "Lista de Termos lida:" << endl;
  lista.print();
  lista.sortSTL();
  cout << "Lista de Termos ordenada:" << endl;
  lista.print();

  cout << "Lista 2: " << endl;
  ifstream dataSet2("datasets/cities.txt");
  if (dataSet2.bad()) {
    cerr << "Não foi possível abrir o arquivo." << endl;
    return;
  }

  i = 0;
  ListaOrdenada<Termo> lista2;
  while (i < 8) {
    string peso;
    string termo;

    while (dataSet2.peek() == ' ') {
      dataSet2.ignore(1);
    };

    getline(dataSet2, peso, '\t');
    long pesoLong = stol(peso);

    getline(dataSet2, termo, '\n');
    Termo termoObj(termo, pesoLong);

    lista2.add(termoObj);

    i++;
  }
  dataSet.close();

  cout << "Lista de Termos lida:" << endl;
  lista2.print();
  lista2.sortCompare();
  cout << "Lista de Termos ordenada:" << endl;
  lista2.print();
}

void testaAutocompletar() {
  ifstream dataSet("datasets/actors.txt");
  if (dataSet.bad()) {
    cerr << "Não foi possível abrir o arquivo." << endl;
    return;
  }

  int i = 1;
  ListaOrdenada<Termo> lista;
  while (!dataSet.eof()) {
    string peso;
    string termo;

    while (dataSet.peek() == ' ') {
      dataSet.ignore(1);
    };
    if (dataSet.eof()) {
      break;
    }

    getline(dataSet, peso, '\t');
    getline(dataSet, termo, '\n');

    try {
      long pesoLong = stol(peso);
      Termo termoObj(termo, pesoLong);
      lista.add(termoObj);
    } catch (const invalid_argument &e) {
      cerr << "Erro de conversão: " << e.what() << " na linha: " << i << endl;
      continue;
    }

    i++;
  }
  dataSet.close();

  lista.sortSTL();

  Autocompletar::searchByPrefix(lista, "Will", 10);
}