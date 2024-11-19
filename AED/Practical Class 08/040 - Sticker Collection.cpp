#include <iostream>
#include <set>

using namespace std;
typedef long long ll;

int main() {
    set<ll> C;
    set<ll> B;
    ll      cCount;
    ll      bCount;
    ll      t;

    cin >> cCount;
    for (ll i = 0; i < cCount; i++) {
        cin >> t;
        C.insert(t);
    }

    cin >> bCount;
    for (ll i = 0; i < bCount; i++) {
        cin >> t;
        B.insert(t);
    }

    for (auto it = B.begin(); it != B.end();)
        if (C.find(*it) != C.end()) it = B.erase(it);
        else it++;

    cout << B.size() << endl;
    if (B.size()) {
        auto it = B.begin();
        cout << *it;
        it++;
        while (it != B.end()) {
            cout << ' ' << *it;
            it++;
        }
        cout << endl;
    }
}
