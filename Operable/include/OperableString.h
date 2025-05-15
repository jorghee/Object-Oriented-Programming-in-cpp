#ifndef OPERABLESTRING_H
#define OPERABLESTRING_H

#include "Operable.h"
#include "OperableVector.h"
#include <string>
#include <vector>
#include <iostream>

class OperableString : public Operable {
private:
  std::vector<std::string> elements;

public:
  OperableString(const std::string& value) : elements{value} {}
  OperableString(const std::vector<std::string>& vec) : elements(vec) {}

  Operable* add(const Operable& other) const override {
    const auto& otherVec = dynamic_cast<const OperableString&>(other);
    size_t n = std::min(elements.size(), otherVec.elements.size());
    std::vector<std::string> result;
    for (size_t i = 0; i < n; ++i)
      result.push_back(elements[i] + otherVec.elements[i]);
    return new OperableString(result);
  }

  Operable* multiply(const Operable& other) const override {
    const auto& repeatVec = dynamic_cast<const OperableVector<int>&>(other);
    size_t n = std::min(elements.size(), repeatVec.getElements().size());
    std::vector<std::string> result;
    for (size_t i = 0; i < n; ++i) {
      std::string temp;
      for (int j = 0; j < repeatVec.getElements()[i]; ++j)
        temp += elements[i];
      result.push_back(temp);
    }
    return new OperableString(result);
  }

  void print() const override {
    std::cout << "[ ";
    for (const auto& val : elements) std::cout << '"' << val << "\" ";
    std::cout << "]\n";
  }
};

#endif
