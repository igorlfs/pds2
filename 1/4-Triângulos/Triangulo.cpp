#include "Triangulo.hpp"
#include "Ponto2D.hpp"
Triangulo::Triangulo(const Ponto2D p1, const Ponto2D p2, const Ponto2D p3) {
    this->_l1 = p1.calcular_distancia(&p2);
    this->_l2 = p2.calcular_distancia(&p3);
    this->_l3 = p3.calcular_distancia(&p1);
}
double Triangulo::calcular_perimetro() const {
    return this->_l1 + this->_l2 + this->_l3;
}
double Triangulo::calcular_area() const{
    double semiP = calcular_perimetro() / 2;  // Semiperímetro

    // Calcule as diferenças entre os lados e o semiPerímetro
    double sP_l1 = semiP - this->_l1;
    double sP_l2 = semiP - this->_l2;
    double sP_l3 = semiP - this->_l3;

    // Use a Fórmula de Heron para calcular a área
    double heron = sqrt(semiP * sP_l1 * sP_l2 * sP_l3);
    return heron;
}
int Triangulo::comparar_area(const Triangulo *triangulo) { 
    if ( this->calcular_area() - triangulo->calcular_area() < 0) return -1;
    if ( this->calcular_area() - triangulo->calcular_area() > 0) return 1;
    else return 0;
}
