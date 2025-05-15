#pragma once
#include "Polygon.h"

class RegularPolygon : public Polygon {
protected:
  int n;
  double l;
  double apo;
public:
  RegularPolygon(const std::vector<Point>& points);
  RegularPolygon(int n, double l, double apo);
  double area() const override;
  std::string type() const override;
};
