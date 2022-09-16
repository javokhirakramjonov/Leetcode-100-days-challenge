import java.util.LinkedList;
import java.util.Queue;

class Solution {

    private class Pair {
        int x, y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public int[][] updateMatrix(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        Queue<Pair> queue = new LinkedList<>();
        int[][] dp = new int[n][m];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = mat[i][j] == 0 ? 0 : Integer.MAX_VALUE;
                if (dp[i][j] == 0)
                    queue.add(new Pair(i, j));
            }
        }

        int[] dx = {0, -1, 0, 1};
        int[] dy = {-1, 0, 1, 0};
        Pair p;
        int x, y;

        while (!queue.isEmpty()) {
            p = queue.remove();
            for (int i = 0; i < 4; ++i) {
                x = p.x + dx[i];
                y = p.y + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && dp[x][y] > dp[p.x][p.y] + 1) {
                    dp[x][y] = dp[p.x][p.y] + 1;
                    queue.add(new Pair(x, y));
                }
            }
        }

        return dp;
    }
}
