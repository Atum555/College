#include "Date2.h"
#include <sstream>
#include <string>

Date::Date() : Date(1, 1, 1) {}

bool isLeapYear(unsigned long year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool validDate(int year, int month, int day) {
    if (year < 1 or year > 9999) return false;
    if (month < 1 or month > 12) return false;
    if (day < 1 or day > 31) return false;

    if (isLeapYear(year) and month == 2) return day <= 29;

    switch (month) {
    case 2 : return day <= 28;
    case 4 :
    case 6 :
    case 9 :
    case 11: return day <= 30;
    default: return true;
    }
}

Date::Date(int year, int month, int day) {
    if (validDate(year, month, day)) {
        this->year  = year;
        this->month = month;
        this->day   = day;
    } else {
        this->year  = 0;
        this->month = 0;
        this->day   = 0;
    }
}

Date::Date(const std::string &year_month_day) {
    std::istringstream str(year_month_day);
    int                year  = 0;
    int                month = 0;
    int                day   = 0;

    str >> year;
    if (str.get() != '/') {
        this->year  = 0;
        this->month = 0;
        this->day   = 0;
        return;
    }
    str >> month;
    if (str.get() != '/') {
        this->year  = 0;
        this->month = 0;
        this->day   = 0;
        return;
    }
    str >> day;

    if (validDate(year, month, day)) {
        this->year  = year;
        this->month = month;
        this->day   = day;
    } else {
        this->year  = 0;
        this->month = 0;
        this->day   = 0;
    }
}

bool Date::is_valid() const { return !(year == 0 or month == 0 or day == 0); }