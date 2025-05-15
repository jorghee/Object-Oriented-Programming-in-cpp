#ifndef OPERABLEMATRIX_H
#define OPERABLEMATRIX_H

#include "Operable.h"
#include <vector>
#include <iostream>

template<typename T>
class OperableMatrix : public Operable {
private:
  std::vector<std::vector<T>> elements;

public:
  OperableMatrix(const std::vector<std::vector<T>>& mat) : elements(mat) {}

  Operable* add(const Operable& other) const override {
    const auto& otherMat = dynamic_cast<const OperableMatrix<T>&>(other);
    size_t rows = std::min(elements.size(), otherMat.elements.size());
    std::vector<std::vector<T>> result;
    for (size_t i = 0; i < rows; ++i) {
      size_t cols = std::min(elements[i].size(), otherMat.elements[i].size());
      std::vector<T> row;
      for (size_t j = 0; j < cols; ++j)
        row.push_back(elements[i][j] + otherMat.elements[i][j]);
      result.push_back(row);
    }
    return new OperableMatrix<T>(result);
  }

  Operable* multiply(const Operable& other) const override {
    const auto& otherMat = dynamic_cast<const OperableMatrix<T>&>(other);
    size_t m = elements.size(), n = elements[0].size(), p = otherMat.elements[0].size();
    std::vector<std::vector<T>> result(m, std::vector<T>(p, T{}));
    for (size_t i = 0; i < m; ++i)
      for (size_t j = 0; j < p; ++j)
        for (size_t k = 0; k < n; ++k)
          result[i][j] += elements[i][k] * otherMat.elements[k][j];
    return new OperableMatrix<T>(result);
  }

  void print() const override {
    for (const auto& row : elements) {
      std::cout << "[ ";
      for (const auto& val : row) std::cout << val << " ";
      std::cout << "]\n";
    }
  }
};

#endif
