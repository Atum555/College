#include "smatrix.h"

bool operator==(const sm_entry &a, const sm_entry &b) { return a.col == b.col and a.row == b.row; }

bool operator<(const sm_entry &a, const sm_entry &b) {
    if (a.row < b.row) return true;
    if (a.row > b.row) return false;
    return a.col < b.col;
}

bool operator>(const sm_entry &a, const sm_entry &b) { return not(a < b) and not(a == b); }

bool operator==(const sm_entry &a, int b) { return a.value == b; }

sm_entry operator+(const sm_entry &a, const sm_entry &b) { return sm_entry{ a.row, a.col, a.value + b.value }; }

void sum(const smatrix &a, const smatrix &b, smatrix &r) {
    r.clear();

    auto aItr = a.begin();
    auto bItr = b.begin();
    while (aItr != a.end() or bItr != b.end()) {
        // Add B if A ended
        if (aItr == a.end()) {
            r.push_back((*bItr));
            bItr++;
            continue;
        }
        // Add A if B ended
        if (bItr == b.end()) {
            r.push_back((*aItr));
            aItr++;
            continue;
        }

        sm_entry aCell = (*aItr);
        sm_entry bCell = (*bItr);
        if (aCell == bCell) {
            sm_entry sum = aCell + bCell;
            if (not(sum == 0)) r.push_back(sum);
            aItr++;
            bItr++;
            continue;
        }
        if (aCell < bCell) {
            r.push_back(aCell);
            aItr++;
            continue;
        }
        if (aCell > bCell) {
            r.push_back(bCell);
            bItr++;
            continue;
        }
    }
}