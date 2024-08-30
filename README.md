# Projeto da Unidade 3 - Autocomplete

Este projeto é parte da Unidade 3 da disciplina de Linguagem de Programação I (LPI). Ele implementa um sistema de autocomplete, semelhante ao utilizado por motores de busca como Google, IMDb, etc. O programa recebe um prefixo como entrada e busca em uma base de dados todos os resultados que correspondem ao prefixo, ordenando os resultados conforme o peso associado a cada termo. Os exemplos abaixo mostram como:

![alt text](image.png)

Nestes exemplos, a aplicação prevê a probabilidade de o usuário digitar cada consulta e apresenta ao usuário uma lista das principais consultas correspondentes, em ordem decrescente de peso. Esses pesos são determinados por dados históricos, como receitas de bilheteria de filmes, frequências de consultas de pesquisa de outros usuários do Google ou histórico de digitação de um usuário de telefone celular. Para efeitos desta atribuição, você terá acesso a um conjunto de todas as termos possíveis e pesos associados (e essas consultas e pesos não serão alterados).

## Estrutura do Projeto

A organização do projeto é a seguinte:

```sh
solution/
├── Autocompletar/
│ ├── autocompletar.cpp
│ └── autocompletar.h
├── Functions/
│ ├── execution.cpp
│ ├── execution.h
│ ├── funcs.h
│ ├── tests.cpp
│ └── tests.h
├── Listas/
│ ├── lista.h
│ └── listaOrdenada.h
├── Termo/
│ ├── termo.cpp
│ └── termo.h
├── datasets/
│ ├── actors.txt
│ ├── cities.txt
│ ├── fortune.txt
│ └── imdb.txt
├── Makefile
└── main.cpp
```

### Descrição das Classes

- **lista.h**: Implementa uma classe `Lista` de TAD, baseada em array, com métodos para adicionar, remover e buscar por índice.
- **listaOrdenada.h**: Classe filha de `Lista`, que implementa métodos de ordenação.
- **termo.h** e **termo.cpp**: Implementam a classe `Termo`, que armazena um termo (string) e seu peso (long), usado para armazenar cada termo da base de dados individualmente.
- **autocompletar.h** e **autocompletar.cpp**: Implementam uma classe estática que processa uma lista de termos e um prefixo recebido, e imprime os resultados encontrados, ordenados por peso de forma decrescente.

## Compilação

Para compilar o programa, utilize o `Makefile` fornecido. Certifique-se de estar no diretório `solution` do projeto (onde o `Makefile` está localizado) e execute o comando:

```bash
make
```
Isso irá gerar um executável chamado Main.

## Execução
Para executar o programa, utilize o seguinte comando:
```bash
./Main <caminho_do_dataset> <quantidade_de_resultados>
```
- `<caminho_do_dataset>`: Caminho para o arquivo de texto contendo os dados que serão usados para o autocomplete. Exemplos: `datasets/actors.txt`, `datasets/imdb.txt`.
- `<quantidade_de_resultados>`: Número máximo de resultados que o programa deve exibir.

### Exemplo de execução
```bash
$ ./Main datasets/actors.txt 10

Entre com o termo a ser auto-completado: (digite "sair" para encerrar o programa): 
Will <ENTER>
2790243210      Will Smith (I)
2739685985      Willem Dafoe
2402502653      William Fichtner
2178370600      Will Ferrell
1737902013      Will Arnett
1674790786      William H. Macy
1589682687      William Melling
1398831928      William Hurt
1172371613      William Shatner
1132672375      William Sadler (I)

Entre com o termo a ser auto-completado: (digite "sair" para encerrar o programa): 
Mary <ENTER>
1811632876      Mary Ellen Trainor
1322246171      Mary Steenburgen
1095979260      Mary Pat Gleason
923434547       Mary Kay Place
805518471       Mary Kay Bergman
751856240       Mary Linda Phillips
666922752       Mary Lynn Rajskub
662564172       Mary Black (I)
655198435       Mary McDonnell (I)
617010839       Mary-Louise Parker

Entre com o termo a ser auto-completado: (digite "sair" para encerrar o programa): 
sair <ENTER>

$
```

## Limpeza
Utilize o comando `make clean` para limpar os objetos e executáveis gerados.

## Observações
Esse projeto foi desenvolvido para fins totalmente educacionais, você pode conferir a proposta original do projeto em https://github.com/kayokgs/20241-imd0030-final_project. O objetivo é condensar todo o contéudo estudado durante o semestre do curso de LPI e coloca-lo em prática, por isso tantos recursos diferentes da linguagem `C++` são utilizados.
