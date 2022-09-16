#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> used(101, vector<bool>(101, false));
        for(int i = 0; i < n; ++ i)
            for(int j = 0; j < m; ++ j)
                if(grid[i][j] == 1) {
                    q.push(mp(mp(i, j), 0));
                    used[i][j] = true;
                }
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int mx = 0;
        pair<pair<int, int>, int> node;
        while(!q.empty()) {
            node = q.front();
            q.pop();
            mx = max(mx, node.second);
            for(int i = 0; i < 4; ++ i) {
                int xx = node.first.first + dx[i];
                int yy = node.first.second + dy[i];
                if(xx >= 0 && xx < n && yy >= 0 && yy < m && !used[xx][yy] && grid[xx][yy] == 0) {
                    used[xx][yy] = true;
                    q.push(mp(mp(xx, yy), node.second + 1));
                }
            }
        }
        return mx == 0 ? -1 : mx;
    }
};
