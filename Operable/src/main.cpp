#include "../include/Operable.h"
#include "../include/OperableVector.h"
#include "../include/OperableString.h"
#include "../include/OperableMatrix.h"

#include <iostream>
#include <memory>
#include <string>

std::shared_ptr<Operable> createEntity(int type) {
  if (type == 1) { // Número como vector de un elemento
    int val;
    std::cout << "Enter a number: ";
    std::cin >> val;
    return std::make_shared<OperableVector<int>>(val);
  } else if (type == 2) { // Vector
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    std::vector<int> values(n);
    std::cout << "Enter elements: ";
    for (int& v : values) std::cin >> v;
    return std::make_shared<OperableVector<int>>(values);
  } else if (type == 3) { // String o lista de strings
    std::cout << "Enter number of strings: ";
    int n;
    std::cin >> n;
    std::vector<std::string> values(n);
    std::cout << "Enter strings: ";
    for (std::string& s : values) std::cin >> s;
    return std::make_shared<OperableString>(values);
  } else if (type == 4) { // Matriz
    int rows, cols;
    std::cout << "Enter number of rows and columns: ";
    std::cin >> rows >> cols;
    std::vector<std::vector<int>> mat(rows, std::vector<int>(cols));
    std::cout << "Enter matrix values row by row:\n";
    for (auto& row : mat)
      for (int& val : row)
        std::cin >> val;
    return std::make_shared<OperableMatrix<int>>(mat);
  }
  return nullptr;
}

int main() {
  std::cout << "==== Operable Entity System ====\n";
  std::cout << "Choose data type:\n";
  std::cout << "1. Number\n2. Vector\n3. String\n4. Matrix\n> ";
  int type;
  std::cin >> type;

  std::cout << "\n--- Enter first operand ---\n";
  auto obj1 = createEntity(type);
  std::cout << "\n--- Enter second operand ---\n";
  auto obj2 = createEntity(type);

  std::cout << "\nChoose operation:\n";
  std::cout << "1. Add\n2. Multiply\n> ";
  int op;
  std::cin >> op;

  std::shared_ptr<Operable> result;
  try {
    if (op == 1)
      result = std::shared_ptr<Operable>(obj1->add(*obj2));
    else if (op == 2)
      result = std::shared_ptr<Operable>(obj1->multiply(*obj2));
    else {
      std::cerr << "Invalid operation selected.\n";
      return 1;
    }

    std::cout << "\nResult: ";
    result->print();
  } catch (const std::bad_cast& e) {
    std::cerr << "Operation failed: incompatible types.\n";
  }

  return 0;
}
