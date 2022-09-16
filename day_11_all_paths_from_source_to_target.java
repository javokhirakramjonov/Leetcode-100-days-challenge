import java.util.LinkedList;
import java.util.List;

class Solution {
    List<List<Integer>> ans = new LinkedList<>();
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        LinkedList<Integer> temp = new LinkedList<>();
        temp.add(0);
        dfs(graph, 0, temp);
        return ans;
    }

    private void dfs(int[][] graph, int pos, LinkedList<Integer> list) {
        if(pos == graph.length - 1) {
            ans.add(list);
            return;
        }
        for(int x: graph[pos]) {
                LinkedList<Integer> temp = new LinkedList<>(list);
                temp.add(x);
                dfs(graph, x, temp);
        }
    }
}
