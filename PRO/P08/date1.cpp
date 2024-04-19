#include "Date1.h"

Date::Date() : Date(1, 1, 1) {}

Date::Date(int year, int month, int day) {
    this->year  = year;
    this->month = month;
    this->day   = day;
}

int Date::get_day() const { return this->day; }

int Date::get_month() const { return this->month; }

int Date::get_year() const { return this->year; }

bool operator<(const Date a, const Date b) {
    if (a.get_year() < b.get_year()) return true;

    if (a.get_year() == b.get_year()) {
        if (a.get_month() < b.get_month()) return true;

        if (a.get_month() == b.get_month()) {
            return a.get_day() < b.get_day();
        }
    };

    return false;
}

bool is_before(const Date &date1, const Date &date2) { return date1 < date2; }