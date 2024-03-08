#ifndef __fraction_h__
#define __fraction_h__

struct fraction {
  int num;
  int den;
};

#include <iostream>
using namespace std;

ostream& operator<<(ostream& out, fraction f) {
  if (f.den == 1) 
    out << f.num;
  else
    out << f.num << '/' << f.den;
  return out;
}

#endif // __fraction_h__
