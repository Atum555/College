#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

int main() {
    map<ll, ll> events;
    ll          count;
    ll          t;

    cin >> count;
    for (ll i = 1; i <= count; i++) {
        cin >> t;
        cout << ((events.find(t) != events.end()) ? events[t] : -1) << (i == count ? "" : " ");
        events[t] = i;
    }
    cout << endl;
}
