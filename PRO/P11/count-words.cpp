#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void count_words(const string &str, vector<pair<string, size_t>> &count) {
    istringstream sstr(str);
    string        word;
    count.clear();

    while (sstr >> word) {
        for (auto &c : word) c = tolower(c);
        bool found = false;
        for (auto &kv : count) {
            if (kv.first != word) continue;
            found = true;
            kv.second++;
        }

        auto itr = count.begin();
        while (!found) {
            if (itr == count.end() or (*itr).first > word) {
                found = true;
                count.insert(itr, { word, 1 });
            }
            itr++;
        }
    }
}

void show_vector(const vector<pair<string, size_t>> &count) {
    cout << "[ ";
    for (const auto &e : count) { cout << e.first << ":" << e.second << ' '; }
    cout << "]\n";
}