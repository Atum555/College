#include "Date3.h"
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

void numberToString(
    const unsigned long n, std::string &str, const unsigned long int size
) {
    std::string   strNumber = std::to_string(n);
    unsigned long d         = size - strNumber.size();
    for (size_t i = 0; i < d; i++) { str.push_back('0'); }
    str += strNumber;
}

Date::Date(int year, int month, int day) {
    if (validDate(year, month, day)) {
        numberToString(year, this->yyyymmdd, 4);
        numberToString(month, this->yyyymmdd, 2);
        numberToString(day, this->yyyymmdd, 2);
    } else {
        this->yyyymmdd = "00000000";
    }
}

Date::Date(const std::string &year_month_day) {
    std::istringstream str(year_month_day);
    int                year  = 0;
    int                month = 0;
    int                day   = 0;

    str >> year;
    if (str.get() != '/') {
        this->yyyymmdd = "00000000";
        return;
    }
    str >> month;
    if (str.get() != '/') {
        this->yyyymmdd = "00000000";
        return;
    }
    str >> day;

    if (validDate(year, month, day)) {
        numberToString(year, this->yyyymmdd, 4);
        numberToString(month, this->yyyymmdd, 2);
        numberToString(day, this->yyyymmdd, 2);
    } else {
        this->yyyymmdd = "00000000";
    }
}

bool Date::is_valid() const {
    return !(
        yyyymmdd.substr(0, 4) == "0000" or yyyymmdd.substr(4, 2) == "00"
        or yyyymmdd.substr(6, 2) == "00"
    );
}