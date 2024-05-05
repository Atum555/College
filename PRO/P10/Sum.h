#ifndef __Sum_h__
#define __Sum_h__

#include "Operation.h"

class Sum : public Operation {
  public:
    Sum(int a, int b) : Operation(a, b) {}

    int operation() const final { return get_op1() + get_op2(); }
};

#endif