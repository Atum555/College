#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

typedef struct team {
    string   name;
    uint64_t wins;
    uint64_t draws;
    uint64_t loses;
    uint64_t points;
    uint64_t goals_scored;
    uint64_t goals_against;
    int64_t goals_average;
} team;

int main() {
    uint64_t N;

    cin >> N;

    vector<team> teams(N);
    for (uint64_t i = 0; i < N; i++) {
        cin >> teams[i].name >> teams[i].wins >> teams[i].draws >> teams[i].loses
            >> teams[i].goals_scored >> teams[i].goals_against;
        teams[i].points        = teams[i].wins * 3 + teams[i].draws;
        teams[i].goals_average = teams[i].goals_scored - teams[i].goals_against;
    }

    // for (const auto t : teams) cout << t.name << " " << t.points << " " << t.goals_average <<
    // endl; cout << endl << endl;

    sort(teams.begin(), teams.end(), [](team a, team b) {
        if (a.points > b.points) return true;
        if (a.points < b.points) return false;
        if (a.goals_average > b.goals_average) return true;
        if (a.goals_average < b.goals_average) return false;
        return a.name < b.name;
    });

    for (const auto t : teams) cout << t.name << " " << t.points << " " << t.goals_average << endl;

    return 0;
}
