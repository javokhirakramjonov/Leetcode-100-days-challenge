class Solution {
    boolean[][] used;
    int n;
    int m;
    boolean surrounded;
    int[][] grid;
    public int closedIsland(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        this.grid = grid;
        used = new boolean[n][m];
        int sum = 0;
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(grid[i][j] == 0 && !used[i][j]) {
                    surrounded = false;
                    dfs(i, j);
                    if(!surrounded)
                        sum++;
                }
            }
        }
        return sum;
    }
                    
    private void dfs(int x, int y) {
        used[x][y] = true;
        if(x == 0 || x == n - 1 || y == 0 || y == m - 1)
            surrounded = true;
        if(x + 1 < n && !used[x + 1][y] && grid[x + 1][y] == 0)
            dfs(x + 1, y);
        if(y + 1 < m && !used[x][y + 1] && grid[x][y + 1] == 0)
            dfs(x, y + 1);
        if(x > 0 && !used[x - 1][y] && grid[x - 1][y] == 0)
            dfs(x - 1, y);
        if(y > 0 && !used[x][y - 1] && grid[x][y - 1] == 0)
            dfs(x, y - 1);
    }
}
