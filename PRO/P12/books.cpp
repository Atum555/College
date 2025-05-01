#include "Book.h"
#include "Page.h"
#include <iostream>

using namespace std;

void Book::build_index(const set<string> &words) {
    index_.clear();
    for (string word : words) {
        // cout << "\u001b[31mLooking for word: " << word << "\u001b[0m" << endl;

        for (size_t i = 0; i < book_.size(); ++i) {
            Page page = book_[i];

            // cout << "\u001b[32mReading Page: " << i + 1 << "\u001b[0m" << endl;

            for (size_t j = 0; j < page.get_num_lines(); ++j) {
                string line = page.get_line(j);

                // cout << "Looking at line: " << j + 1 << " | " << line << endl;

                if (line.find(word) == string::npos) continue;

                // cout << "Word Found!" << endl;

                if (index_.find(word) == index_.end()) index_[word] = {};
                index_[word].insert(i + 1);

                // this->show_index();
                break;
            }
            // cout << endl;
        }
    }
}
