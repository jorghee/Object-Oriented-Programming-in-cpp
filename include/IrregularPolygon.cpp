#include "IrregularPolygon.h"
#include <cmath>
using namespace std;

IrregularPolygon::IrregularPolygon(const std::vector<Point>& points)
    : Polygon(points) {}

double IrregularPolygon::area() const {
  double sum = 0.0;
  const vector<Point>& pts = getVertices();
  int n = pts.size();

  for (int i = 0; i < n; ++i) {
    const Point& p1 = pts[i];
    const Point& p2 = pts[(i + 1) % n];
    sum += (p1.x * p2.y) - (p2.x * p1.y);
  }

  return 0.5 * abs(sum);
}

string IrregularPolygon::type() const {
  return "Irregular Polygon";
}
