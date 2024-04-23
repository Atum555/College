#ifndef __Power_h__
#define __Power_h__

#include "Operation.h"

class Power : public Operation {
  public:
    Power(int a, int b) : Operation(a, b) {}

    int operation() const final {
        if (get_op2() == 0) return 1;
        int a      = get_op1();
        int result = a;
        for (int i = 1; i < get_op2(); i++) { result *= a; }
        return result;
    }
};

#endif