#include <iostream>

#include "Cotacao.hpp"
#include "HistoricoBovespa.hpp"
using std::cin;
int main() {
  HistoricoBovespa historico;
  std::cout << "teste\n";
  while (1) {
    string *siglas = new string;
    string *datas = new string;
    double *valores = new double;
    cin >> *siglas >> *datas >> *valores;
    if (cin.good())
      historico.inserir_cotacao(*siglas, *datas, *valores);
    delete siglas;
    delete datas;
    delete valores;
    if (cin.eof())
      break;
  }
  historico.imprimir_estatisticas_completas();
}
