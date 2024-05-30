#include "Date2.h"
#include <sstream>
#include <string>

using namespace std;

bool isLeapYear(unsigned long year) { return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)); }

bool isValidDate(int year, int month, int day) {
    if (1 > year or year > 9999) return false;
    if (1 > month or month > 12) return false;
    if (1 > day or day > 31) return false;

    switch (month) {
    case 4:
    case 6:
    case 9:
    case 11:
        if (day > 30) return false;
        break;
    case 2:
        if (isLeapYear(year) and day > 29) return false;
        else if (day > 28) return false;
    }

    return true;
}

Date::Date() : Date(1, 1, 1) {}

Date::Date(int year_, int month_, int day_) {
    if (not isValidDate(year_, month_, day_)) {
        year  = 0;
        month = 0;
        day   = 0;
        return;
    }
    year  = year_;
    month = month_;
    day   = day_;
}

Date::Date(const std::string &year_month_day) {
    istringstream iss(year_month_day);
    bool          invalid = false;

    iss >> year;
    if (iss.get() != '/') invalid = true;

    iss >> month;
    if (iss.get() != '/') invalid = true;

    iss >> day;

    if (not isValidDate(year, month, day)) invalid = true;

    if (invalid) {
        year  = 0;
        month = 0;
        day   = 0;
    }
}

int Date::get_year() const { return year; }

int Date::get_month() const { return month; }

int Date::get_day() const { return day; }

bool Date::is_valid() const {
    if (year == 0 or month == 0 or day == 0) return false;
    return true;
}