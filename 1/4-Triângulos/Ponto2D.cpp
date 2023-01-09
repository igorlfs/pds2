#include "Ponto2D.hpp"
Ponto2D::Ponto2D(){
    this->_x = 0;
    this->_y = 0;
}
Ponto2D::Ponto2D(double x, double y) {
    this->_x = x;
    this->_y = y;
}
double Ponto2D::calcular_distancia(const Ponto2D* ponto) const{
    double dist_x = this->_x - ponto->_x;
    double dist_y = this->_y - ponto->_y;
    return (sqrt(dist_x * dist_x + dist_y * dist_y));
}
