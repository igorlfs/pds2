#include <iostream>

#include "Aluno.hpp"
#include "BST.hpp"
#include "avaliacao_basica_bst.hpp"
int main() {
  avaliacao_basica();
  BST bts;
  int matricula;
  string nome;
  while (cin >> matricula >> nome) {
    Aluno *aluno = new Aluno;
    aluno->set_matricula(matricula);
    aluno->set_nome(nome);
    if (cin.good())
      bts.inserir_aluno(*aluno);
    delete aluno;
    if (cin.eof())
      break;
  }
  bts.imprimir_arvore();
  return 0;
}
