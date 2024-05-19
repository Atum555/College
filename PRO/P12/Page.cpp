#include "Page.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Page::Page() {}

void Page::add_line(const string &line) { page_.push_back(line); }

string Page::get_line(size_t line_num) const { return page_.at(line_num); }

void Page::clear() { page_.clear(); }

size_t Page::get_num_lines() const { return page_.size(); }

void Page::show() const {
    for (const string &line : page_) cout << line << endl;
    cout << endl;
}
