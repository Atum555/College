#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
  public:
    // constructor
    Student(const std::string &name, const std::string &id, short ac, short p1, short p2);
    // accessors
    std::string get_id() const;
    std::string get_name() const;
    // member function
    double      actual_grade() const; // [0..20]
  private:
    std::string name_;
    std::string id_;
    short       ac_, p1_, p2_; // [0..20]
};

#endif
