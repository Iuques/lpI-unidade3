#ifndef TESTS_H
#define TESTS_H

#include "../Autocompletar/autocompletar.h"
#include "../Listas/listaOrdenada.h"
#include "../Termo/termo.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/*
  Definição das funções de teste
*/

// Testes relacionados a classe Lista e ListaOrdenada
void testaLista();
// Testes relacionados a classe Termo
void testaTermo();
// Testes que relacionam a classe ListaOrdenada com a classe Termo
void testaListaTermos();
// Testes relacionados a classe Autocompletar
void testaAutocompletar();

#endif