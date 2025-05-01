#include "smatrix.h"

void sum(const smatrix &a, const smatrix &b, smatrix &r) {
    size_t ia = 0;
    size_t ib = 0;

    while (true) {
        if (ia == a.size() && ib == b.size()) return;
        else if (ia == a.size()) {
            r.push_back(sm_entry{ b[ib].row, b[ib].col, b[ib].value });
            ++ib;
        } else if (ib == b.size()) {
            r.push_back(sm_entry{ a[ia].row, a[ia].col, a[ia].value });
            ++ia;
        } else if (a[ia].row == b[ib].row) {
            if (a[ia].col == b[ib].col) {
                if (a[ia].value + b[ib].value)
                    r.push_back(sm_entry{ a[ia].row, a[ia].col, a[ia].value + b[ib].value });
                ++ia;
                ++ib;
            } else if (a[ia].col < b[ib].col) {
                r.push_back(sm_entry{ a[ia].row, a[ia].col, a[ia].value });
                ++ia;
            } else if (b[ib].col < a[ia].col) {
                r.push_back(sm_entry{ b[ib].row, b[ib].col, b[ib].value });
                ++ib;
            }
        } else if (a[ia].row < b[ib].row) {
            r.push_back(sm_entry{ a[ia].row, a[ia].col, a[ia].value });
            ++ia;
        } else if (b[ib].row < a[ia].row) {
            r.push_back(sm_entry{ b[ib].row, b[ib].col, b[ib].value });
            ++ib;
        }
    }
}
