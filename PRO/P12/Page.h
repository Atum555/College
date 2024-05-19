#ifndef PAGE_H
#define PAGE_H

#include <string>
#include <vector>

class Page {
  public:
    Page();
    void        add_line(const std::string &line);
    std::string get_line(size_t line_num) const;
    // bool has_word(const string& word) const;
    size_t      get_num_lines() const;
    void        clear();
    void        show() const;
    // ... other function members
  private:
    std::vector<std::string> page_;
};

#endif
