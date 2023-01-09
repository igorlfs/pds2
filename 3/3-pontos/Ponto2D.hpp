#ifndef PONTO_2D
#define PONTO_2D
#include "Ponto4D.hpp"
// Implmenta um ponto bidimensional.
class Ponto2D : public Ponto4D {
public:
  // Implementação aqui pois é mais simples que ter um source com 4 linhas
  int dimensao() const override { return 2; };
  // Use o construtor do ponto 4D com as duas últimas coordenadas nulas
  Ponto2D(double x, double y) : Ponto4D(x, y, 0, 0) {}
};

#endif
