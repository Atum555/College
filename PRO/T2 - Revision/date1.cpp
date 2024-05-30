#include "Date1.h"

Date::Date() : Date(1, 1, 1) {}

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}

int Date::get_year() const { return year; }

int Date::get_month() const { return month; }

int Date::get_day() const { return day; }

bool is_before(const Date &date1, const Date &date2) {
    if (date1.get_year() < date2.get_year()) return true;
    if (date1.get_year() > date2.get_year()) return false;

    if (date1.get_month() < date2.get_month()) return true;
    if (date1.get_month() > date2.get_month()) return false;

    return date1.get_day() < date2.get_day();
}