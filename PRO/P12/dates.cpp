#include "Date.h"
#include <algorithm>
#include <ostream>
#include <vector>

using namespace std;

bool operator<(const Date &a, const Date &b) {
    if (a.getYear() < b.getYear()) return true;
    if (a.getYear() > b.getYear()) return false;
    if (a.getMonth() < b.getMonth()) return true;
    if (a.getMonth() > b.getMonth()) return false;
    return a.getDay() < b.getDay();
}

ostream &operator<<(ostream &out, const Date a) {
    if (a.getYear() < 10) out << "000";
    else if (a.getYear() < 100) out << "00";
    else if (a.getYear() < 1000) out << "0";
    out << a.getYear() << '/';

    if (a.getMonth() < 10) out << "0";
    out << a.getMonth() << '/';

    if (a.getDay() < 10) out << "0";
    out << a.getDay();

    return out;
}