#ifndef DATE_H
#define DATE_H

class Date {
public:
  Date(int year = 1, int month = 1, int day = 1) 
    : year_(year), month_(month), day_(day) { }
  int getYear() const { return year_; }
  int getMonth() const { return month_; }
  int getDay() const { return day_; }
private:
  int year_, month_, day_;
};

#endif
