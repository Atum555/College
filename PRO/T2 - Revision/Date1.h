#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>

// A simple class Date definition
class Date {
  public:
    // constructors
    Date();
    Date(int year, int month, int day);
    // accessors
    int get_year() const;
    int get_month() const;
    int get_day() const;
    // write the date as "yyyy/mm/dd"
    void write() const; 

  private:
    int year;
    int month;
    int day;
    // compute the number of days of month/year, for internal use only
    static int num_days(int year, int month);
};

void Date::write() const {
  std::cout << std::setfill('0')
            << std::setw(4) << year << '/'
            << std::setw(2) << month << '/'
            << std::setw(2) << day;
}

int Date::num_days(int year, int month) {
  int n_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    return 29;
  return n_days[month - 1];
}

// Redefine assert() for internal use only (not using cerr in CodeRunner tests)
#define assert(e, m) { if (! (e)) std::cout << m; }

#endif