#include "Cotacao.hpp"

// Getters
string Cotacao::get_data() const { return this->data; }
double Cotacao::get_valor() const { return this->valor; }

// Setters
void Cotacao::set_data(string _data) { this->data = _data; }
void Cotacao::set_valor(double _valor) { this->valor = _valor; }

// Construtores
Cotacao::Cotacao(string _data, double _valor) {
  this->data = _data;
  this->valor = _valor;
}
