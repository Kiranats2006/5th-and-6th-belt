#include <iostream>
#include <vector>
using namespace std;

int getMaximumGold(vector<vector<int>>& grid, int x, int y) {
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0) {
        return 0;
    }

    int gold = grid[x][y];
    grid[x][y] = 0;  // Mark the cell as visited

    int maxGold = 0;
    maxGold = max(maxGold, getMaximumGold(grid, x - 1, y));  // up
    maxGold = max(maxGold, getMaximumGold(grid, x + 1, y));  // down
    maxGold = max(maxGold, getMaximumGold(grid, x, y - 1));  // left
    maxGold = max(maxGold, getMaximumGold(grid, x, y + 1));  // right

    grid[x][y] = gold;  // Backtrack
    return gold + maxGold;
}

int getMaximumGold(vector<vector<int>>& grid) {
    int maxGold = 0;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 0) {
                maxGold = max(maxGold, getMaximumGold(grid, i, j));
            }
        }
    }
    return maxGold;
}

int main() {
    int m, n;
    cin >> m >> n;  // Read grid dimensions

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];  // Read grid values
        }
    }

    cout << getMaximumGold(grid) << endl;

    return 0;
}
