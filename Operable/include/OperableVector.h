#ifndef OPERABLEVECTOR_H
#define OPERABLEVECTOR_H

#include "Operable.h"
#include <vector>
#include <iostream>
#include <type_traits>

template<typename T>
class OperableVector : public Operable {
private:
  std::vector<T> elements;

public:
  OperableVector(const T& scalar) : elements{scalar} {}
  OperableVector(const std::vector<T>& vec) : elements(vec) {}

  Operable* add(const Operable& other) const override {
    const auto& otherVec = dynamic_cast<const OperableVector<T>&>(other);
    size_t n = std::min(elements.size(), otherVec.elements.size());
    std::vector<T> result;
    for (size_t i = 0; i < n; ++i)
        result.push_back(elements[i] + otherVec.elements[i]);
    return new OperableVector<T>(result);
  }

  Operable* multiply(const Operable& other) const override {
    const auto& otherVec = dynamic_cast<const OperableVector<T>&>(other);
    size_t n = std::min(elements.size(), otherVec.elements.size());
    std::vector<T> result;
    for (size_t i = 0; i < n; ++i)
      result.push_back(elements[i] * otherVec.elements[i]);
    return new OperableVector<T>(result);
  }

  const std::vector<T>& getElements() const { return elements; }

  void print() const override {
    std::cout << "[ ";
    for (const auto& val : elements) std::cout << val << " ";
    std::cout << "]\n";
  }

};

#endif
