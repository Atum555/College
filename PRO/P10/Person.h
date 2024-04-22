#ifndef PERSON_H
#define PERSON_H

#include <sstream>
#include <string>
using namespace std;

class Person {
  public:
    Person(int id, const string &name) : id_(id), name_(name) {}

    int id() const { return id_; }

    const string &name() const { return name_; }

    virtual string to_string() const {
        ostringstream out;
        out << id_ << '/' << name_;
        return out.str();
    }

  private:
    int    id_;
    string name_;
};

#endif
