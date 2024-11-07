#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    string words;
    getline(cin, words);

    int wc = 0;
    for (char c : words)
        if (c == ' ') wc++;

    int N;
    cin >> N;

    list<string> children(N);
    for (auto it = children.begin(); it != children.end(); it++) cin >> *it;

    auto it = children.begin();
    int  offset;
    while (!children.empty()) {
        offset = wc % children.size();
        for (size_t i = 0; i < offset; i++)
            if (++it == children.end()) it = children.begin();

        cout << *it << endl;
        it = children.erase(it);
        if (it == children.end()) it = children.begin();
    }
}
