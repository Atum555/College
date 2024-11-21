#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

int main() {
    map<ll, ll> sequence;
    ll          n;
    ll          t;

    cin >> n;

    for (ll i = 0; i < n; i++) {
        cin >> t;
        sequence[t]++;
    }

    ll deletions = 0;
    for (auto p : sequence)
        if (p.first < p.second) deletions += p.second - p.first;
        else if (p.first > p.second) deletions += p.second;

    cout << deletions << endl;
}
