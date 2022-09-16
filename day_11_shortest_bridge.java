import java.util.LinkedList;
import java.util.Queue;

class Solution {
    private boolean[][] used;
    Queue<int[]> queue = new LinkedList<>();
    int[][] grid;
    int n, m;

    public int shortestBridge(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        used = new boolean[n][m];
        this.grid = grid;

        just:
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    break just;
                }
            }
        }

        int[] p;
        int x, y;
        int mn = n + m;
        while (!queue.isEmpty()) {
            p = queue.remove();
            x = p[0];
            y = p[1];
            if (x > 0 && !used[x - 1][y]) {
                used[x - 1][y] = true;
                if (grid[x - 1][y] == 1) {
                    mn = Math.min(mn, p[2]);
                } else
                    queue.add(new int[]{x - 1, y, p[2] + 1});
            }
            if (y > 0 && !used[x][y - 1]) {
                used[x][y - 1] = true;
                if (grid[x][y - 1] == 1) {
                    mn = Math.min(mn, p[2]);
                } else
                    queue.add(new int[]{x, y - 1, p[2] + 1});
            }
            if (x + 1 < n && !used[x + 1][y]) {
                used[x + 1][y] = true;
                if (grid[x + 1][y] == 1) {
                    mn = Math.min(mn, p[2]);
                } else
                    queue.add(new int[]{x + 1, y, p[2] + 1});
            }
            if (y + 1 < m && !used[x][y + 1]) {
                used[x][y + 1] = true;
                if (grid[x][y + 1] == 1) {
                    mn = Math.min(mn, p[2]);
                } else
                    queue.add(new int[]{x, y + 1, p[2] + 1});
            }
        }

        return mn;
    }

    private void dfs(int x, int y) {
        used[x][y] = true;
        queue.add(new int[]{x, y, 0});
        if (x > 0 && !used[x - 1][y] && grid[x - 1][y] == 1)
            dfs(x - 1, y);
        if (y > 0 && !used[x][y - 1] && grid[x][y - 1] == 1)
            dfs(x, y - 1);
        if (x + 1 < n && !used[x + 1][y] && grid[x + 1][y] == 1)
            dfs(x + 1, y);
        if (y + 1 < m && !used[x][y + 1] && grid[x][y + 1] == 1)
            dfs(x, y + 1);
    }
}
