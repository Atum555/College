#ifndef ERASMUS_STUDENT_H
#define ERASMUS_STUDENT_H

#include "Student.h"

class ErasmusStudent : public Student {
  public:
    ErasmusStudent(
        int id, const string &name, const string &course, const string &country
    )
        : Student(id, name, course), country_(country) {}

    const string &country() const { return country_; }

    string to_string() const {
        ostringstream out;
        out << id() << '/' << name() << '/' << course() << '/' << country_;
        return out.str();
    }

  private:
    string country_;
};

#endif