#include "HistoricoBovespa.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>
using std::cout;
using std::endl;

auto compara = [](const Cotacao &c1, const Cotacao &c2) {
  return c1.get_valor() < c2.get_valor();
};
/* Adaptado de:
 * https://stackoverflow.com/questions/52635339/getting-the-max-element-in-a-vector-of-objects-from-a-custom-class
 *
 * Por padrão, não tem como o max_element funcionar em
 * elementos do tipo "cotacao" (afinal, como saber que uma cotação é
 * maior que outra?). Para poder realizar essa operação, podemos
 * criar a nossa própria função de comparação para esse tipo.
 *
 * Confesso que não compreendi perfeitamente a sintaxe
 * (Qual o signficado dos colchetes?)
 * E nem qual seria o tipo se não usasse o auto
 *
 * Além disso, perceba que o max_element faz a comparação
 * usando o operador matemático '<'. Ou seja, o elemento que
 * "reprovar" em todas as comparação é que, de fato, o maior.
 *
 * Em contra partida, não preciso fazer uma função diferente
 * para o min_element: ele também usa o < para fazer a comparação.
 * É claro que nesse caso, o menor elemento é aprovado em todos os testes. */
Cotacao *criaCotacao(string data, double valor) {
  Cotacao *cotaAuxiliar = new Cotacao;
  cotaAuxiliar->set_data(data);
  cotaAuxiliar->set_valor(valor);
  return cotaAuxiliar;
}
void HistoricoBovespa::inserir_cotacao(string sigla, string data,
                                       double valor) {
  Colecao[sigla].push_back(*criaCotacao(data, valor));
}
double HistoricoBovespa::calcular_valor_medio_acao(string sigla) {
  double soma = 0;
  int n = 0;
  vector<Cotacao> cotacoes = Colecao[sigla];
  for (auto iT = cotacoes.begin(); iT != cotacoes.end(); iT++) {
    soma += iT->get_valor();
    n++;
  }
  return (double)soma / n;
}

Cotacao *HistoricoBovespa::recuperar_cotacao_maxima_acao(string sigla) {
  Cotacao *maior = nullptr;
  maior =
      &*std::max_element(Colecao[sigla].begin(), Colecao[sigla].end(), compara);
  return maior;
}
Cotacao *HistoricoBovespa::recuperar_cotacao_minima_acao(string sigla) {
  Cotacao *menor = nullptr;
  menor =
      &*std::min_element(Colecao[sigla].begin(), Colecao[sigla].end(), compara);
  return menor;
}
void HistoricoBovespa::imprimir_estatisticas_completas() {
  cout << std::fixed << std::showpoint;
  cout << std::setprecision(2);
  for (auto iT : Colecao) {
    cout << iT.first << " ";
    for (auto jT : iT.second) {
      cout << jT.get_valor() << " ";
    }
    cout << "| " << recuperar_cotacao_minima_acao(iT.first)->get_valor() << " "
         << recuperar_cotacao_maxima_acao(iT.first)->get_valor() << " "
         << calcular_valor_medio_acao(iT.first) << endl;
  }
}
