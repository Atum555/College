#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct course {
    std::string name;    // {"ALGA", "AMI", ...}
    float       credits; // [1.5, 4.5, 6}]
    short       grade;   // [0..20]
};

class Student {
  public:
    // constructor with parameters
    Student(const std::string &id);
    // accessor
    std::string get_id() const;
    // member functions
    void        add(const course &c); // add a course grade
    double      avg() const;          // calculate the average grade
  private:
    std::string         id_;
    std::vector<course> courses_;
};

#endif