#include "../include/OperableString.h"
#include "../include/OperableVector.h"

Operable* OperableString::add(const Operable& other) const {
  const auto& otherStr = dynamic_cast<const OperableString&>(other);
  size_t n = std::min(elements.size(), otherStr.elements.size());
  std::vector<std::string> result;
  for (size_t i = 0; i < n; ++i)
    result.push_back(elements[i] + otherStr.elements[i]);
  return new OperableString(result);
}

Operable* OperableString::multiply(const Operable& other) const {
  const auto& repeatVec = dynamic_cast<const OperableVector<int>&>(other);
  size_t n = std::min(elements.size(), repeatVec.getElements().size());
  std::vector<std::string> result;
  for (size_t i = 0; i < n; ++i)
    result.push_back(std::string(repeatVec.getElements()[i], elements[i][0]));
  return new OperableString(result);
}

void OperableString::print() const {
  std::cout << "[ ";
  for (const auto& s : elements) std::cout << '"' << s << "\" ";
  std::cout << "]\n";
}

