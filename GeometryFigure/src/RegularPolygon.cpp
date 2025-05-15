#include "RegularPolygon.h"
#include <cmath>
#include <sstream>

// Constructor
RegularPolygon::RegularPolygon(const std::vector<Point>& points) : Polygon(points) {}

// Method to calculate the area of the regular polygon
double RegularPolygon::area() const {
    return n*l*apo*0.5;
}

// Method to return the type of the polygon
std::string RegularPolygon::type() const {
    //TODO
}
RegularPolygon::RegularPolygon(int n, double l, double apo){
  this->n = n;
  this->l = l;
  this->apo = apo;
}
