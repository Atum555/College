#ifndef __Operation_h__
#define __Operation_h__

class Operation {
public:
  Operation(int op1, int op2) : op1_(op1), op2_(op2) { }
  int get_op1() const { return op1_; }
  int get_op2() const { return op2_; }
  virtual int operation() const = 0;  // operation
private:
  int op1_, op2_;  // two operands
};

#endif