#include <iostream>

#include "Point.h"

std::ostream &operator<<(std::ostream &out, const Point &p) {
  out << '(' << p.getX() << ", " << p.getY() << ')';
  return out;
}

std::istream &operator>>(std::istream &in, Point &p) {
  // Talvez seria melhor usar setters
  in >> p.x >> p.y;
  return in;
}

Point Point::operator+(const Point &p) {
  Point s;
  s.x = this->getX() + p.getX();
  s.y = this->getY() + p.getY();
  return s;
}

Point &Point::operator+=(const Point &p) {
  this->x = this->getX() + p.getX();
  this->y = this->getY() + p.getY();
  return *this;
}
