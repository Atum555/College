#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<bool>> &cells, vector<vector<bool>> &visited, int i, int j) {
    visited[i][j] = true;
    int count     = 1;

    // For all children
    for (int ii = i - 1; ii <= i + 1; ii++)
        for (int jj = j - 1; jj <= j + 1; jj++)
            // If valid position
            if (ii >= 0 and ii < cells.size())
                if (jj >= 0 and jj < cells[0].size())
                    // If exists and not visited
                    if (cells[ii][jj] and not visited[ii][jj]) count += dfs(cells, visited, ii, jj);

    return count;
}

int main() {
    int                  N;
    int                  R, C;
    vector<vector<bool>> cells;
    vector<vector<bool>> visited;
    char                 t;
    int                  count;
    int                  maxSize;

    cin >> N;

    for (int _ = 0; _ < N; _++) {
        // Read Size
        cin >> R >> C;

        // Mark all as unvisited
        visited.assign(R, vector<bool>(C, false));

        // Read cells
        cells.assign(R, vector<bool>(C, false));
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                cin >> t;
                if (t == '#') cells[i][j] = true;
            }

        // Clear results
        count = maxSize = 0;

        // Check all cells
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                // If there's anything there and it's not visited
                // DFS the component
                if (cells[i][j] and not visited[i][j]) {
                    count++;
                    maxSize = max(maxSize, dfs(cells, visited, i, j));
                }

        cout << count << " " << maxSize << endl;
    }
}
