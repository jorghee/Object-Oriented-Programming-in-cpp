#pragma once
#include <string>

class GeometricFigure {
public:
  virtual double area() const = 0;
  virtual std::string type() const = 0;

  virtual ~GeometricFigure() = default;
};
