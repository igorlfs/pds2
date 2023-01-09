#pragma once
#include <string>
using std::string;
struct Cotacao {
  // Variáveis
  string data;
  double valor;

  // Getters
  string get_data() const;
  double get_valor() const;

  // Setters
  void set_data(string _data);
  void set_valor(double _valor);

  // Construtores
  Cotacao(string _data, double _valor);
  Cotacao() = default;
};
