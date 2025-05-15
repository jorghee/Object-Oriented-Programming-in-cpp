#include "../include/OperableVector.h"
#include "../include/OperableMatrix.h"
#include "../include/OperableString.h"
#include <memory>

int main() {
  Operable* num1 = new OperableVector<int>(5);
  Operable* num2 = new OperableVector<int>(10);
  std::unique_ptr<Operable> numSum(num1->add(*num2));
  std::unique_ptr<Operable> numMul(num1->multiply(*num2));

  std::cout << "Number sum: "; numSum->print();
  std::cout << "Number product: "; numMul->print();

  Operable* vec1 = new OperableVector<float>({1.0f, 2.0f});
  Operable* vec2 = new OperableVector<float>({3.0f, 4.0f});
  std::unique_ptr<Operable> vecSum(vec1->add(*vec2));
  std::unique_ptr<Operable> vecMul(vec1->multiply(*vec2));

  std::cout << "Vector sum: "; vecSum->print();
  std::cout << "Vector product: "; vecMul->print();

  Operable* mat1 = new OperableMatrix<int>({{1, 2}, {3, 4}});
  Operable* mat2 = new OperableMatrix<int>({{5, 6}, {7, 8}});
  std::unique_ptr<Operable> matSum(mat1->add(*mat2));
  std::unique_ptr<Operable> matMul(mat1->multiply(*mat2));

  std::cout << "Matrix sum:\n"; matSum->print();
  std::cout << "Matrix product:\n"; matMul->print();

  Operable* str1 = new OperableString("Hi");
  Operable* str2 = new OperableString("There");
  std::unique_ptr<Operable> strSum(str1->add(*str2));
  std::cout << "String concatenation: "; strSum->print();

  delete num1; delete num2;
  delete vec1; delete vec2;
  delete mat1; delete mat2;
  delete str1; delete str2;

  return 0;
}
