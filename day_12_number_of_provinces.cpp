#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> used;
    
    void dfs(vector<vector<int>>& graph, int node) {
        used[node] = true;
        for(int &x: graph[node]) {
            if(!used[x]) {
                dfs(graph, x);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        used.resize(201, false);
        vector<vector<int>> graph(201);
        int n = isConnected.size();
        int m = isConnected[0].size();
        for(int i = 0; i < n; ++ i) {
            for(int j = i; j < m; ++ j) {
                if(isConnected[i][j] == 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++ i) {
            if(!used[i]) {
                ans ++;
                dfs(graph, i);
            }
        }
        return ans;
    }
};
