#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

void show_map(const map<string, size_t> &count) {
    cout << "[ ";
    for (const auto &e : count) { cout << e.first << ":" << e.second << ' '; }
    cout << "]\n";
}

void count_words(const string &str, map<string, size_t> &count) {
    istringstream iss(str);
    count.clear();
    string word;
    while (iss >> word) {
        for (char &c : word) c = tolower(c);

        auto itr = count.find(word);
        if (itr == count.end()) count[word] = 1;
        else count[word]++;
    }
}
