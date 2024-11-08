#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Process {
    string    name;
    u_int64_t time;
};

int main() {
    u_int64_t      T;
    u_int64_t      N;
    string         name;
    u_int64_t      time;
    queue<Process> processes;
    u_int64_t      iteration;
    u_int64_t      totalTime;
    Process        p;

    // Read Data
    cin >> T >> N;
    for (size_t i = 0; i < N; i++) {
        cin >> name >> time;
        processes.push(Process{ name, time });
    }

    iteration = 0;
    totalTime = 0;
    while (not processes.empty()) {
        iteration++;
        p = processes.front();
        if (p.time <= T) {
            totalTime += p.time;
            cout << p.name << ' ' << totalTime << ' ' << iteration << endl;
        } else {
            totalTime += T;
            processes.push(Process{ p.name, p.time - T });
        }
        processes.pop();
    }
}
