#include "Person.h"
#include <algorithm>
#include <fstream>
#include <vector>

Person::Person(
    const std::string &name, const std::string &address,
    const std::string &phone
)
    : name_(name), address_(address), phone_(phone) {}

std::string Person::get_name() const { return name_; }

std::string Person::get_address() const { return address_; }

std::string Person::get_phone() const { return phone_; }

void read_persons_data(
    const std::string &file_name, std::vector<Person> &persons
) {
    std::ifstream inf(file_name);
    std::string   name;
    while (std::getline(inf, name)) {
        std::string addr;
        std::string phone;
        std::getline(inf, addr);
        std::getline(inf, phone);
        Person p(name, addr, phone);
        persons.push_back(p);
    }
}

struct less_than_Person_Name {
    inline bool operator()(const Person &struct1, const Person &struct2) {
        return (struct1.get_name() < struct2.get_name());
    }
};

void sort_persons_by_name(std::vector<Person> &persons) {
    std::sort(persons.begin(), persons.end(), less_than_Person_Name());
}