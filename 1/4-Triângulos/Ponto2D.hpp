#pragma once

#include <cmath>
struct Ponto2D {
    double _x;
    double _y;
    Ponto2D();
    Ponto2D(double x, double y);
    double calcular_distancia(const Ponto2D* ponto) const;
};
