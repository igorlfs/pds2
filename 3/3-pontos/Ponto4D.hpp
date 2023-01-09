#ifndef PONTO_4D
#define PONTO_4D

#include "Ponto.hpp"

// Implementa um ponto quadridimensional.
class Ponto4D : public Ponto {
protected:
  double _coordenadas[4];

public:
  int dimensao() const override { return 4; };
  Ponto4D(double x, double y, double z, double w);
  double posicao(int k) const override;
  double distancia(Ponto *p) const override;
};

#endif
