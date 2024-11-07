#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct groom {
    int  position;
    char type;
};

struct couple {
    int  groom;
    int  bride;
    char type;
};

int main() {
    vector<couple> couples;
    stack<groom>   grooms;
    string         expression;
    bool           deuBosta;
    char           c;

    cin >> expression;

    deuBosta = false;
    for (int i = 0; i < expression.size(); i++) {
        // cout << deuBosta << " " << i << " " << expression[i] << " "
        //      << (grooms.empty() ? '_' : grooms.top().type) << endl;

        if (deuBosta) break;

        c = expression[i];
        switch (c) {
        case '(':
        case '{':
        case '[': grooms.push(groom{ i, c }); break;

        case ')':
            if (grooms.empty() or grooms.top().type != '(') {
                deuBosta = true;
                break;
            }
            couples.push_back(couple{ grooms.top().position, i, grooms.top().type });
            grooms.pop();
            break;
        case '}':
            if (grooms.empty() or grooms.top().type != '{') {
                deuBosta = true;
                break;
            }
            couples.push_back(couple{ grooms.top().position, i, grooms.top().type });
            grooms.pop();
            break;
        case ']':
            if (grooms.empty() or grooms.top().type != '[') {
                deuBosta = true;
                break;
            }
            couples.push_back(couple{ grooms.top().position, i, grooms.top().type });
            grooms.pop();
            break;
        default: break;
        }
    }

    if (deuBosta or not grooms.empty()) cout << "badly matched pairs" << endl;
    else if (couples.empty()) cout << "no brides and grooms to marry" << endl;
    else {
        for (const couple &c : couples) {
            cout << c.type;
            if (c.type == '(') cout << ')';
            if (c.type == '[') cout << ']';
            if (c.type == '{') cout << '}';
            cout << ' ' << c.groom << ' ' << c.bride << endl;
        }
    }
}
