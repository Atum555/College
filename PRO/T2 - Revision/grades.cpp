#include "Student.h"
#include <string>

Student::Student(const std::string &id) : id_(id) {}

std::string Student::get_id() const { return id_; }

void Student::add(const course &c) { courses_.push_back(c); }

double Student::avg() const {
    double creditsSum = 0;
    double gradesSum  = 0;
    for (course c : courses_) {
        creditsSum += c.credits;
        gradesSum  += c.grade * c.credits;
    }
    return gradesSum > 0 ? gradesSum / creditsSum : 0;
}