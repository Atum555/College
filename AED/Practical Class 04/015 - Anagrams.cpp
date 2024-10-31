#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

string sortPhrase(const string &s) {
    string newS;
    for (const char &c : s)
        if (isalnum(c)) newS += tolower(c);

    sort(newS.begin(), newS.end());
    return newS;
}

int main() {
    uint64_t              N;
    string                t;
    vector<string>        inputs;
    unordered_set<string> single;
    unordered_set<string> classes;

    // Read data
    cin >> N;
    for (uint64_t i = 0; i <= N; i++) {
        getline(cin, t);
        //cout << t << " : " << sortPhrase(t) << endl;
        inputs.push_back(sortPhrase(t));
    }

    //cout << endl;

    for (const auto &s : inputs) {
        //cout << s << endl;

        // If in classes ignore
        if (classes.find(s) != classes.end()) continue;

        // If in single add to classes
        if (single.find(s) != single.end()) {
            //cout << "Added to classes!" << endl;
            classes.insert(s);
        } else single.insert(s); // If not add to single
    }

    cout << classes.size() << endl;

    return 0;
}
