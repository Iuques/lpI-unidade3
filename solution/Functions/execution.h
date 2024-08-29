#ifndef EXECUTION_H
#define EXECUTION_H

#include "../Autocompletar/autocompletar.h"
#include "../Listas/listaOrdenada.h"
#include "../Termo/termo.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/*
  Definição da função principal de execução do programa
*/

// Recebe o caminho do arquivo de entrada e o limite "k" de resultados a serem impressos
int executeProject(string dataPath, int k);

#endif