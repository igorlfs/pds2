#include "Ponto4D.hpp"
#include <assert.h>
#include <cmath>
Ponto4D::Ponto4D(double x, double y, double z, double w) {
  double coordenadas[4] = {x, y, z, w};
  for (int i = 0; i < 4; ++i) {
    this->_coordenadas[i] = coordenadas[i];
  }
}
double Ponto4D::posicao(int k) const {
  // Certifique-se de que a k é válido
  assert(0 <= k && k <= this->dimensao());
  // Lembre-se de deslocar uma unidade pra baixo (contagem humana)
  return this->_coordenadas[k - 1];
}
double Ponto4D::distancia(Ponto *p) const {
  assert(this->dimensao() == p->dimensao());

  double dist = 0;
  for (int i = 1; i <= this->dimensao(); ++i) {
    dist += pow((this->posicao(i) - p->posicao(i)), 2);
  }
  dist = sqrt(dist);

  return dist;
}
