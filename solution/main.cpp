#include "Functions/execution.h"
// #include "Functions/tests.h"
#include <cstdlib>

/*
  Este programa recebe um prefixo e busca todos os termos que começam com esse
  prefixo dentro de um arquivo de dados desejado, ordenando a lista de termos
  por peso.
*/

// Recebe o caminho do arquivo e o limite de termos a serem retornados como
// parâmetros posicionais
int main(int argc, char *argv[]) {
  // Checa se os parâmetros foram passados corretamente
  if (argc != 3) {
    // Demonstra como executar o programa corretamente
    cerr << "Informe: " << argv[0] << " <string> <int>" << endl;
    return 1;
  }

  // Passa os parâmetros posicionais para variáveis
  char *dataPath = argv[1];
  int k = atoi(argv[2]);

  // Executa o programa e recebendo o retorno na variável "check"
  int check = executeProject(dataPath, k);
  // Repete a execução até que o retorno seja diferente de 0 (quando o usuário
  // digitar "sair" ou ocorrer algum erro)
  while (check == 0) {
    check = executeProject(dataPath, k);
  }

  /*
    Funções de testes individuais de cada classe
  */

  // testaLista();
  // testaTermo();
  // testaListaTermos();
  // testaAutocompletar();

  return 0;
}