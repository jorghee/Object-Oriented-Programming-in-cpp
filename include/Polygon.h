#pragma once
#include "GeometryFigure.h"
#include "Point.h"
#include <vector>

class Polygon : public GeometricFigure {
protected:
  std::vector<Point> vertices;

public:
  Polygon(const std::vector<Point>& points);
  const std::vector<Point>& getVertices() const;
};
