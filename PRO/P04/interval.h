#ifndef __intervals_h__
#define __intervals_h__

struct time_of_day {
  unsigned char h; // Hours [0,23]
  unsigned char m; // Minutes [0,59]
};

struct interval {
  time_of_day start; // Start time
  time_of_day end;   // End time
};

#include <iostream>
using namespace std;

ostream& operator<<(ostream& out, time_of_day t) {
  if (t.h < 10) out << '0';
  out << (int) t.h << ':';
  if (t.m < 10) out << '0';
  out << (int) t.m;
  return out;
}

ostream& operator<<(ostream& out, interval il) {
  return out << '[' << il.start << ',' << il.end << '[';
}

#endif // __intervals_h__
