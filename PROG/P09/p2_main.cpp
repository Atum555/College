#include "Date.h"
#include "Person.h"
#include <iostream>
#include <vector>

void born_before(const std::vector<Person> &persons, const Date &date) {
    date.show();
    std::cout << ":";

    for (Person p : persons) {
        if (p.get_birth_date().is_before(date)) {
            std::cout << " ";
            p.show();
        }
    }
}
