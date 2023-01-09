#pragma once
#include "Ponto2D.hpp"
struct Triangulo {
    // (comprimento) dos lados do triângulo
    double _l1;
    double _l2;
    double _l3;
    Triangulo(const Ponto2D p1, const Ponto2D p2, const Ponto2D p3);

    double calcular_perimetro() const;
    double calcular_area() const;
    int comparar_area(const Triangulo *triangulo);
};
