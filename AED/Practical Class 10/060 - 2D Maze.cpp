#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int                   N;
    int                   R, C;
    vector<vector<bool>>  cells;
    vector<vector<bool>>  visited;
    vector<vector<int>>   distance;
    queue<pair<int, int>> q;
    char                  t;
    pair<int, int>        P;
    pair<int, int>        T;

    cin >> N;

    // For each map
    for (int _ = 0; _ < N; _++) {
        cin >> R >> C;
        cells.assign(R, vector<bool>(C, false));
        visited.assign(R, vector<bool>(C, false));
        distance.assign(R, vector<int>(C, 0));

        // Read Inputs
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                cin >> t;
                if (t == '.' or t == 'P' or t == 'T') cells[i][j] = true;
                if (t == 'P') P = { i, j };
                if (t == 'T') T = { i, j };
            }

        // Add P to queue
        q = queue<pair<int, int>>();
        q.push(P);
        visited[P.first][P.second] = true;

        // Calculate distances to each cell
        while (!q.empty()) {
            pair<int, int> father = q.front();
            q.pop();

            // Neighbor position above
            int i = father.first - 1;
            int j = father.second;

            // If is free and not visited
            if (cells[i][j] and not visited[i][j]) {
                q.push({ i, j });
                visited[i][j]  = true;
                distance[i][j] = distance[father.first][father.second] + 1;
            }

            // Neighbor position under
            i = father.first + 1;
            j = father.second;

            // If is free and not visited
            if (cells[i][j] and not visited[i][j]) {
                q.push({ i, j });
                visited[i][j]  = true;
                distance[i][j] = distance[father.first][father.second] + 1;
            }

            // Neighbor position left
            i = father.first;
            j = father.second - 1;

            // If is free and not visited
            if (cells[i][j] and not visited[i][j]) {
                q.push({ i, j });
                visited[i][j]  = true;
                distance[i][j] = distance[father.first][father.second] + 1;
            }

            // Neighbor position right
            i = father.first;
            j = father.second + 1;

            // If is free and not visited
            if (cells[i][j] and not visited[i][j]) {
                q.push({ i, j });
                visited[i][j]  = true;
                distance[i][j] = distance[father.first][father.second] + 1;
            }
        }

        cout << distance[T.first][T.second] << endl;
    }


    return 0;
}
