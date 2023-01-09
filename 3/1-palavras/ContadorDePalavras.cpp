#include "ContadorDePalavras.hpp"
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
ContadorDePalavras::ContadorDePalavras() {}
void ContadorDePalavras::Adicionar(string s) {
  Palavra word(s);
  for (auto it = _lista_de_palavras.begin(); it != _lista_de_palavras.end();
       ++it) {
    if (s == it->palavra()) {
      it->Incrementar();
      return;
    }
  }
  this->_lista_de_palavras.push_back(word);
}
void ContadorDePalavras::ImprimirOrdenado() {
  // Otimização: só ordene quando necesário imprimir
  this->_lista_de_palavras.sort();
  for (auto it = _lista_de_palavras.begin(); it != _lista_de_palavras.end();
       ++it) {
    cout << it->palavra() << ' ' << it->ocorrencias() << endl;
  }
}
