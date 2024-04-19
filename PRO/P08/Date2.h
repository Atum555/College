#ifndef DATE_H
#define DATE_H

#include <iomanip>
#include <iostream>
#include <string>

class Date {
  public:
    // constructors
    Date();
    Date(int year, int month, int day);
    Date(const std::string &year_month_day);
    // accessors
    int  get_year() const;
    int  get_month() const;
    int  get_day() const;
    // tests date validity
    bool is_valid() const;
    // write the date as "yyyy/mm/dd"
    void write() const;

  private:
    int        year;
    int        month;
    int        day;
    // Compute the number of days of month
    static int num_days(int year, int month);
};

void Date::write() const {
    std::cout << std::setfill('0') << std::setw(4) << year << '/'
              << std::setw(2) << month << '/' << std::setw(2) << day;
}

#endif