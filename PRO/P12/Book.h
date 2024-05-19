#ifndef BOOK_H
#define BOOK_H

#include "Page.h"
#include <map>
#include <set>
#include <string>
#include <vector>

class Book {
  public:
    Book();
    bool import(const std::string &filename);
    void build_index(const std::set<std::string> &words);
    void show_book() const;
    void show_index() const;
    // ... other function members
  private:
    std::vector<Page>                       book_;  // the pages
    std::map<std::string, std::set<size_t>> index_; // the index
                                                    // ... other data members
};

#endif
