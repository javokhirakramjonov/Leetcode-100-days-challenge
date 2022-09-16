#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool used[501][501];
    int n = 0, m = 0;
    int temp = 0;
    vector<vector<int>> grid;

    void goWalk(int x, int y) {
        used[x][y] = true;
        if (x + 1 < n && grid[x + 1][y] == 1 && !used[x + 1][y])
            goWalk(x + 1, y);
        if (x > 0 && grid[x - 1][y] == 1 && !used[x - 1][y])
            goWalk(x - 1, y);
        if (y + 1 < m && grid[x][y + 1] == 1 && !used[x][y + 1])
            goWalk(x, y + 1);
        if (y > 0 && grid[x][y - 1] == 1 && !used[x][y - 1])
            goWalk(x, y - 1);
    }

    int numEnclaves(vector<vector<int>> &grid) {
        n = (int) grid.size();
        m = (int) grid[0].size();
        int ans = 0;
        this->grid = grid;
        for(int i = 0; i < n; ++ i) {
            if(grid[i][0] == 1 && !used[i][0])
                goWalk(i, 0);
            if(grid[i][m - 1] == 1 && !used[i][m - 1])
                goWalk(i, m - 1);
        }
        for(int i = 0; i < m; ++ i) {
            if(grid[0][i] == 1 && !used[0][i])
                goWalk(0, i);
            if(grid[n - 1][i] == 1 && !used[n - 1][i])
                goWalk(n - 1, i);
        }
        for(int i = 0; i < n; ++ i)
            for(int j = 0; j < m; ++ j)
                ans += !used[i][j] * grid[i][j];
        return ans;
    }
};
