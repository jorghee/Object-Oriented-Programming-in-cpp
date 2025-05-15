#pragma once
#include "Polygon.h"

class IrregularPolygon : public Polygon {
public:
  IrregularPolygon(const std::vector<Point>& points);

  double area() const override;
  std::string type() const override;
};
