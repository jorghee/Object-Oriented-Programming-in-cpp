#ifndef OPERABLE_H
#define OPERABLE_H

class Operable {
public:
  virtual Operable* add(const Operable& other) const = 0;
  virtual Operable* multiply(const Operable& other) const = 0;
  virtual void print() const = 0;

  virtual ~Operable() = default;
};

#endif
