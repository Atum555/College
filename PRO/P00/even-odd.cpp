#include <iostream>
using namespace     std;

int
main() {
    int x;
    cin >> x;
    if (x % 2 == 0) {
        cout << x << " is even\n";
    }
    else {
        cout << x << " is odd\n";
    }
    return 0;
}