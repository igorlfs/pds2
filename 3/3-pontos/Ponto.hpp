#ifndef PONTO_H
#define PONTO_H

#include <iostream>
#include <string>

using std::string;

// Interface que representa cada ponto, independente de sua dimensão.
class Ponto {
public:
  // Retorna um inteiro que representa a dimensão do ponto.
  virtual int dimensao() const = 0;

  // Retorna o valor da k-ésema posição do ponto.
  // Ex: seja o ponto {1, 2, 3}; então posicao(1) = 1
  // PRECONDIÇÃO: k é um valor entre 1 e dimensao().
  virtual double posicao(int k) const = 0;

  // Computa a distância entre o Ponto armazenado no objeto e o Ponto passado
  // por parâmetro. PRECONDIÇÃO: os pontos devem ter a mesma dimensão.
  virtual double distancia(Ponto *p) const = 0;

  // Destrutor virtual.
  virtual ~Ponto(){};
};

#endif
