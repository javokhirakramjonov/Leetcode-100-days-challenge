import java.util.LinkedList;
import java.util.List;

class Solution {

    private boolean[] used;

    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        used = new boolean[rooms.size()];
        dfs(rooms, 0);
        for(int i = 0; i < rooms.size(); ++ i) 
            if(!used[i])
                return false;
        return true;
    }

    private void dfs(List<List<Integer>> graph, int pos) {
        used[pos] = true;
        for (int x : graph.get(pos))
            if (!used[x])
                dfs(graph, x);
    }
}
