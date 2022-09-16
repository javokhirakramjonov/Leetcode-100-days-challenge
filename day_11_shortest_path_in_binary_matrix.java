import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    int n, m;
    boolean[][] used;

    Queue<State> queue = new LinkedList<>();

    public int shortestPathBinaryMatrix(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        if(grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;
        if(n == 1 && m == 1 && grid[0][0] == 0)
            return 1;
        used = new boolean[n][m];
        queue.add(new State(0, 0, 1));
        used[0][0] = true;
        State current;
        int[] dx = {-1, -1, -1, 0, 1, 1, 1, 0};
        int[] dy = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!queue.isEmpty()) {
            current = queue.remove();
            for(int i = 0; i < 8; ++ i) {
                int x = current.x + dx[i];
                int y = current.y + dy[i];
                if(x >= 0 && x < n && y >= 0 && y < m && !used[x][y] && grid[x][y] == 0) {
                    used[x][y] = true;
                    if(x == n - 1 && y == n - 1) {
                        return current.distance + 1;
                    }
                    queue.add(new State(x, y, current.distance + 1));
                }
            }
        }
        return -1;
    }
}

class State {
    int x;
    int y;
    int distance;

    public State(int x, int y, int distance) {
        this.x = x;
        this.y = y;
        this.distance = distance;
    }
}
