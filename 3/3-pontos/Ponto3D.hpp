#ifndef PONTO_3D
#define PONTO_3D
#include "Ponto4D.hpp"

// Implmenta um ponto tridimensional.
class Ponto3D : public Ponto4D {
public:
  int dimensao() const override { return 3; };
  // Use o construtor do ponto 4D com a última coordenada nula
  Ponto3D(double x, double y, double z) : Ponto4D(x, y, z, 0) {}
};

#endif
