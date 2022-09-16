#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n, m;
    bool used[501][501];
    vector<vector<int>> a, b;
    bool similar;

    void count(int x, int y) {
        used[x][y] = true;
        if (a[x][y] != b[x][y])
            similar = false;
        if (x + 1 < n && !used[x + 1][y] && b[x + 1][y] == 1)
            count(x + 1, y);
        if (x > 0 && !used[x - 1][y] && b[x - 1][y] == 1)
            count(x - 1, y);
        if (y + 1 < m && !used[x][y + 1] && b[x][y + 1] == 1)
            count(x, y + 1);
        if (y > 0 && !used[x][y - 1] && b[x][y - 1] == 1)
            count(x, y - 1);
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        a = grid1;
        b = grid2;
        n = a.size();
        m = a[0].size();
        int ans = 0;
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(b[i][j] == 1 && !used[i][j]) {
                    similar = true;
                    count(i, j);
                    ans += similar;
                }
            }
        }
        return ans;
    }
};
