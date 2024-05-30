#include <fstream>
#include <string>

using namespace std;

int count(const string &fname, const string &word) {
    string sWord;
    for (char c : word) sWord.push_back(tolower(c));

    ifstream       ifs(fname);
    string        rWord;
    unsigned long count = 0;
    while (ifs >> rWord) {
        for (char &c : rWord) c = tolower(c);
        if (rWord == sWord) ++count;
    }
    return count;
}