class Solution {
public:
    vector<bool> used;
    vector<vector<int>> graph;
    void dfs(int node) {
        used[node] = true;
        for(int subNode: graph[node]) {
            if(!used[subNode]) {
                dfs(subNode);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        used.resize(n);
        graph.resize(n);
        int components = 0;
        int m = connections.size();
        for(int i = 0; i < m; ++ i) {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i = 0; i < n; ++ i) {
            if(!used[i]){
                ++components;
                dfs(i);
            }
        }
        if(n <= m + 1)
            return components - 1;
        return -1;
    }
};
