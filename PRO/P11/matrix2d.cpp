#include <iostream>
#include <vector>

using namespace std;

void show_vector(const vector<vector<int>> &v) {
    cout << "{";
    for (const auto &line : v) {
        cout << "{ ";
        for (const auto &elem : line) cout << elem << ' ';
        cout << "}";
    }
    cout << "}";
}

bool max_filter(vector<vector<int>> &v, int n) {
    if (n % 2 != 1) return false;
    if (v.size() < (size_t)n) return false;
    if (v[0].size() < (size_t)n) return false;

    size_t sizeI = v.size();
    size_t sizeJ = v[0].size();
    for (auto innerV : v)
        if (innerV.size() != sizeJ) return false;

    vector<vector<int>> r;

    for (size_t i = 0; i < sizeI; i++) {
        r.push_back({});
        for (size_t j = 0; j < sizeJ; j++) {
            int m = v[i][j];

            for (int a = -(n / 2); a <= n / 2; a++) {
                for (int b = -n / 2; b <= n / 2; b++) {
                    if (i + a < 0 or i + a >= sizeI) continue;
                    if (j + b < 0 or j + b >= sizeJ) continue;
                    m = max(m, v[i + a][j + b]);
                }
            }

            r[i].push_back(m);
        }
    }
    v = r;
    return true;
}