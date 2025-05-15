#ifndef OPERABLESTRING_H
#define OPERABLESTRING_H

#include "Operable.h"
#include <vector>
#include <string>
#include <iostream>

class OperableString : public Operable {
private:
  std::vector<std::string> elements;

public:
  OperableString(const std::string& val) : elements{val} {}
  OperableString(const std::vector<std::string>& vec) : elements(vec) {}

  Operable* add(const Operable& other) const override;
  Operable* multiply(const Operable& other) const override;
  void print() const override;
};

#endif
