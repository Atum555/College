#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>

// using namespace std;

class Person {
  public:
    Person(const std::string &name, const std::string &address, const std::string &phone);
    std::string get_name() const;
    std::string get_address() const;
    std::string get_phone() const;

  private:
    std::string name_;    // Name
    std::string address_; // Address
    std::string phone_;   // Phone
};

void show_persons_data(const std::vector<Person> &persons) {
    std::cout << "[\n";
    for (const auto &p : persons) {
        std::cout << "  " << p.get_name() << " : " << p.get_address() << " : " << p.get_phone()
                  << '\n';
    }
    std::cout << "]\n";
}

#endif
