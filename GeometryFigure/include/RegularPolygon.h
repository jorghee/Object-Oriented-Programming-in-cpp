#pragma once
#include "Polygon.h"

class RegularPolygon : public Polygon {
public:
  RegularPolygon(const std::vector<Point>& points);

  double area() const override;
  std::string type() const override;
};
