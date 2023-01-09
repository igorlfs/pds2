/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include "polygon.hpp"
#include <algorithm>
#include <iostream>

std::ostream &operator<<(std::ostream &out, const Polygon &poly) {
  for (const Point &p : poly.limits) {
    out << " " << p;
  }
  return out;
}

bool equalsHelper(const std::vector<Point> x, const std::vector<Point> y) {
  for (int i = 0; i < x.size(); ++i) {
    for (int j = 0; j < y.size(); ++j) {
      if (x[i].contains(y[j])) {
        break;
      } else if (j == y.size() - 1) {
        return false;
      }
    }
  }
  return true;
}
bool operator==(const Polygon &lhs, const Polygon &rhs) {
  std::vector<Point> left = lhs;
  std::vector<Point> right = rhs;
  return (equalsHelper(lhs, rhs) && equalsHelper(rhs, lhs));
}

bool Point::contains(const Point &p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream &operator<<(std::ostream &out, const Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point &p) const {
  if (p.x >= this->limits[0].x && p.x <= this->limits[2].x &&
      p.y >= this->limits[0].x && p.y <= this->limits[2].y) {
    return true;
  }
  return false;
}

Point::Point(int xx, int yy) : x(xx), y(yy) { this->limits.push_back(*this); }

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
  Point p[4] = {
      {std::min(x0, x1), std::min(y0, x1)},
      {std::min(x0, x1), std::max(y0, y1)},
      {std::max(x0, x1), std::max(y0, y1)},
      {std::max(x0, x1), std::min(y0, y1)},
  };
  for (int i = 0; i < 4; ++i) {
    this->limits.push_back(p[i]);
  }
}
