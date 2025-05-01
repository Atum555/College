#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
  public:
    Date(); // 1/1/1
    Date(int year, int month, int day);
    bool is_before(const Date &date) const;

    void show() const { std::cout << year_ << '/' << month_ << '/' << day_; }

  private:
    int year_, month_, day_;
};

#endif
