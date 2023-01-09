#include "ContadorDePalavras.hpp"
#include <fstream>
#include <iostream>
#include <string>

using std::cin;
using std::ifstream;

int main(int argc, char *argv[]) {
  ContadorDePalavras contador;
  string s;
  string flagInput = "-i";
  if (!flagInput.string::compare(argv[1])) {
    ifstream entradaArquivo(argv[2]);
    if (!entradaArquivo.good()) {
      perror("Erro na leitura do arquivo:");
      exit(1);
    }
    entradaArquivo >> s;
    while (s != ".") {
      contador.Adicionar(s);
      entradaArquivo >> s;
    }
  } else {
    cin >> s;
    while (s != ".") {
      contador.Adicionar(s);
      cin >> s;
    }
  }
  contador.ImprimirOrdenado();
  return 0;
}
