#include "termo.h"

// Construtor padrão, inicializa o Termo com dados arbitrários
Termo::Termo() {
  termo = "";
  peso = 0;
};

// Construtor com parâmetros, inicializa o Termo com os dados passados
Termo::Termo(string termo_, long peso_) {
  termo = termo_;
  peso = peso_;
}

// Comparador de inteiros comum, implementado igualmente aos métodos de
// comparação em funcs.cpp
int Termo::comparaPeloPeso(Termo t1, Termo t2) {
  if (t1.peso > t2.peso) {
    return 1;
  } else if (t1.peso == t2.peso) {
    return 0;
  } else {
    return -1;
  }
}

// Compara os primeiros 'r' caracteres de uma string com outra
int Termo::comparaPeloPrefixo(Termo t1, Termo t2, int r) {
  // Loop que percorre os primeiros r caracteres de uma string
  for (int i = 0; i < r; i++) {
    // Checa se os caracteres são diferentes e retorna 1 ou -1, dependendo de
    // qual é maior
    if (t1.termo[i] > t2.termo[i])
      return 1;
    if (t1.termo[i] < t2.termo[i]) {
      return -1;
    }
  }

  // Caso passe por todo o loop, os caracteres são iguais então retorna 0
  return 0;
}

// Compara o atributo termo com uma string
int Termo::comparaPrefixoComString(string s) {
  // Checa se o tamanho da string é maior que o do termo
  if (s.size() > termo.size()) {
    // Caso seja, retorna o valor 2 para ser tratado de forma diferente
    return 2;
  }

  // Comparador igual ao implementado no método 'comparaPeloPrefixo'
  for (string::size_type i = 0; i < s.size(); i++) {
    if (this->termo[i] > s[i]) {
      return 1;
    }
    if (this->termo[i] < s[i]) {
      return -1;
    }
  }

  return 0;
}

// Checa se o peso de um termo é válido, usado em Autocomplete para descartar
// retornos inválidos da busca binária
bool Termo::isPesoValido() {
  // Checa se o peso é negativo
  if (peso < 0) {
    // Se for, retorna falso
    return false;
  }
  // Se não for, retorna verdadeiro
  return true;
}

// Sobrecarga do operador "="
Termo &Termo::operator=(const Termo &other) {
  // Checa se o objeto é o próprio objeto
  if (this == &other) {
    // Caso seja, retorna o próprio objeto
    return *this;
  }

  // Copia os dados do objeto 'other' para o objeto atual
  this->termo = other.termo;
  this->peso = other.peso;
  // Retorna o objeto atual
  return *this;
}

// Sobrecarga do operador de comparação "=="
bool Termo::operator==(Termo t) {
  // Checa se o atributo termo é menor que o termo passado como parâmetro
  if (this->termo == t.termo) {
    // Caso seja, retorna verdadeiro
    return true;
  } else {
    // Caso contrário, retorna falso
    return false;
  }
}

// Sobrecarga do operador de comparação "<"
bool Termo::operator<(Termo t) {
  // Checa se o atributo termo é menor que o termo passado como parâmetro
  if (this->termo < t.termo) {
    // Caso seja, retorna verdadeiro
    return true;
  } else {
    // Caso contrário, retorna falso
    return false;
  }
}

// Sobrecarga do operador de output "<<"
std::ostream &operator<<(std::ostream &out, const Termo &t) {
  // Faz com que a saída seja no formato "peso <tab> termo"
  out << t.peso << "\t" << t.termo;
  return out;
}

// Imprime os dados do termo (usado para testes)
void Termo::printData() {
  cout << "Termo: " << termo << ", "
       << "Peso: " << peso << endl;
}

// Imprime os resultados obtidos pelo método "comparaPeloPeso" (usado para
// testes)
void Termo::testeCompPeso(Termo t) {
  if (comparaPeloPeso(*this, t) == 1) {
    cout << this->peso << " é maior que " << t.peso << endl;
  } else if (comparaPeloPeso(*this, t) == 0) {
    cout << this->peso << " é igual a " << t.peso << endl;
  } else {
    cout << this->peso << " é menor que " << t.peso << endl;
  }
}
// Imprime os resultados obtidos pelo método "comparaPeloPrefixo" (usado para
// testes)
void Termo::testeCompPref(Termo t, int r) {
  if (comparaPeloPrefixo(*this, t, r) == 1) {
    cout << "As primeiras " << r << " letras de " << this->termo
         << " vem depois de " << t.termo << endl;
  } else if (comparaPeloPrefixo(*this, t, r) == 0) {
    cout << "As primeiras " << r << " letras de " << this->termo
         << " são iguais as de " << t.termo << endl;
  } else {
    cout << "As primeiras " << r << " letras de " << this->termo
         << " vem antes de " << t.termo << endl;
  }
}