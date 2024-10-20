/*     +--+--+--+--+--+--+
|  +2  |21|22|23|24|25|26|
|      +--+--+--+--+--+--+
|  +1  |20|07|08|09|10|27|
      +--+--+--+--+--+--+
Y   0  |19|06|01|02|11|28|
       +--+--+--+--+--+--+
|  -1  |18|05|04|03|12|29|
|      +--+--+--+--+--+--+
|  -2  |17|16|15|14|13|30|
|      +--+--+--+--+--+--+

        -2 -1  0 +1 +2 +3
       ------- X --------*/

// Given a number N belonging to a spiral
// like the one above, compute its
// coordinates

#include <iostream>

using namespace std;

int main() {
    long number;

    // Read input
    cin >> number;

    // Numbers at (cor,cor) where cor >=0
    // are every second square number
    // like 1, 9, 25, 49...
    // Find out in which ring the number is located.

    long cor = 0;

    while ((cor * 2 + 1) * (cor * 2 + 1) <= number) cor++;

    // Number is in the ring where (cor, cor) is
    long delta = (cor * 2 + 1) * (cor * 2 + 1) - number;

    // Number is in the top row
    if (delta <= cor * 2) cout << '(' << cor - delta << ',' << cor << ')' << endl;

    // Number is in the left column
    else if (delta <= cor * 4) cout << '(' << -cor << ',' << cor - (delta - cor * 2) << ')' << endl;

    // Number is in the bottom row
    else if (delta <= cor * 6) cout << '(' << -cor + (delta - cor * 4) << ',' << -cor << ')' << endl;

    // Number is in the right column
    else cout << '(' << cor << ',' << -cor + (delta - cor * 6) << ')' << endl;

    return 0;
}
