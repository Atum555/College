#include <iostream>
#include <set>

using namespace std;
typedef long long ll;

int main() {
    multiset<ll> alice;
    multiset<ll> bob;
    ll           aliceCount;
    ll           bobCount;
    ll           t;

    cin >> aliceCount;
    for (ll i = 0; i < aliceCount; i++) {
        cin >> t;
        alice.insert(t);
    }

    cin >> bobCount;
    for (ll i = 0; i < bobCount; i++) {
        cin >> t;
        bob.insert(t);
    }

    while (alice.size() and bob.size()) {
        auto ait = --alice.end();
        auto bit = --bob.end();

        if (*ait > *bit) {
            t  = *ait;
            t -= *bit;
            alice.insert(t);
        } else if (*ait < *bit) {
            t  = *bit;
            t -= *ait;
            bob.insert(t);
        }

        alice.erase(ait);
        bob.erase(bit);
    }

    if (alice.size()) {
        cout << "Alice wins" << endl;
        cout << alice.size() << endl;
    } else if (bob.size()) {
        cout << "Bob wins" << endl;
        cout << bob.size() << endl;
    } else {
        cout << "Tie" << endl;
        cout << 0 << endl;
    }
}
