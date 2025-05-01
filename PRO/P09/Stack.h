#ifndef STACK_H
#define STACK_H

#include <iomanip>
#include <iostream>
#include <vector>

template <typename T>
class Stack {
  public:
    Stack();
    size_t size() const;
    bool   peek(T &elem) const;
    bool   pop(T &elem);
    void   push(const T &elem);

  private:
    std::vector<T> elements;
};

#endif
