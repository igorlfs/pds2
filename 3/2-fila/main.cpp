#include "fila_de_prioridade.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
int main(int numArgumentos, char *argumento[]) {
  FilaDePrioridade fila;
  string nome;
  int idade;

  // Lê os dados e insere na fila de prioridade.
  // Leitura também pode ser a partir de arquivo (para depuração)
  if (argumento[1] != nullptr) {
    ifstream entradaArquivo(argumento[1]);
    if (!entradaArquivo.good()) {
      perror("Erro na leitura do arquivo:");
    }
    while (entradaArquivo >> nome >> idade) {
      fila.Inserir(idade, nome);
    }
  } else {
    while (cin >> nome >> idade) {
      fila.Inserir(idade, nome);
    }
  }
  // Imprime os nomes em ordem de prioridade.
  while (!fila.vazia()) {
    cout << fila.primeiro() << endl;
    fila.RemoverPrimeiro();
  }
  return 0;
}
