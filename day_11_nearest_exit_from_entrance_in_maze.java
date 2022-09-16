import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int nearestExit(char[][] maze, int[] entrance) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{entrance[0], entrance[1], 0});

        int n = maze.length;
        int m = maze[0].length;
        boolean[][] used = new boolean[n][m];
        used[entrance[0]][entrance[1]] = true;
        int[] temp;
        int x, y;

        while(!queue.isEmpty()) {
            temp = queue.remove();
            x = temp[0];
            y = temp[1];
            if(!(x == entrance[0] && y == entrance[1]) && (x == 0 || y == 0 || x == n - 1 || y == m - 1))
                return temp[2];
            if(x > 0 && !used[x - 1][y] && maze[x - 1][y] == '.') {
                used[x - 1][y] = true;
                queue.add(new int[]{x - 1, y, temp[2] + 1});
            }
            if(y > 0 && !used[x][y - 1] && maze[x][y - 1] == '.') {
                used[x][y - 1] = true;
                queue.add(new int[]{x, y - 1, temp[2] + 1});
            }
            if(x + 1 < n && !used[x + 1][y] && maze[x + 1][y] == '.') {
                used[x + 1][y] = true;
                queue.add(new int[]{x + 1, y, temp[2] + 1});
            }
            if(y + 1 < m && !used[x][y + 1] && maze[x][y + 1] == '.') {
                used[x][y + 1] = true;
                queue.add(new int[]{x, y + 1, temp[2] + 1});
            }
        }
        return -1;
    }
}
