#include "execution.h"

int executeProject(string dataPath, int k) {
  // Tenta abrir o arquivo de dados
  ifstream dataSet(dataPath);
  // Checa se o caminho do arquivo de dados passado é válido
  if (!dataSet.is_open()) {
    // Caso não seja, exibe uma mensagem de erro e retorna -1
    cerr << "Caminho do arquivo inválido." << endl;
    return -1;
  }

  // Recebe o prefixo a ser buscado
  string prefixo;
  cout << endl;
  cout << "Entre com o termo a ser auto-completado: (digite \"sair\" para "
          "encerrar o programa): ";
  cin >> prefixo;

  // Checa se o usuário digitou "sair", caso sim, retorna -1
  if (prefixo == "sair") {
    return -1;
  }

  // Inicializa uma lista de termos
  ListaOrdenada<Termo> lista;
  // Inicializa um contador para manter conta da linha atual sendo lida
  int i = 1;
  // Loop que dura até que todo o arquivo seja lido
  while (!dataSet.eof()) {
    // Inicializa as variáveis para armazenar o peso e o termo
    string peso;
    string termo;

    // Ignora espaços em branco no início do arquivo
    while (dataSet.peek() == ' ') {
      dataSet.ignore(1);
    };
    // Mais um check se o arquivo chegou ao fim, necessário pois alguns espaços
    // foram ignorados
    if (dataSet.eof()) {
      break;
    }

    // Lê a linha até um <tab> e armazena o valor lido na variável "peso"
    getline(dataSet, peso, '\t');
    // Lê a linha até o final da linha e armazena o valor lido na variável
    // "termo"
    getline(dataSet, termo, '\n');

    // Tenta converter o peso para um long int
    try {
      long pesoLong = stol(peso);
      // Caso consiga, cria um objeto Termo com o termo e o peso lidos
      Termo termoObj(termo, pesoLong);
      // Adiciona o objeto na lista
      lista.add(termoObj);
    } catch (const invalid_argument &e) {
      // Caso não consiga, exibe uma mensagem de erro informando a linha e
      // continua o loop
      cerr << "Erro de conversão: " << e.what() << " na linha: " << i << endl;
      continue;
    }

    // Incrementa o contador de linha
    i++;
  }
  // Fecha o arquivo de dados
  dataSet.close();

  // Ordena a lista por ordem alfabética
  lista.sortSTL();

  // Busca os termos que começam com o prefixo passado
  Autocompletar::searchByPrefix(lista, prefixo, k);

  // Retorna 0 para indicar sucesso na execução
  return 0;
}