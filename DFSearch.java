public class DFSearch {
    private Graph g;
    private int s;
    private boolean[] visited;
    int count;

    public DFSearch(Graph g, int s) {
        this.g = g;
        this.s = s;
        visited = new boolean[g.V()];
        dfs(s);
    }

    private void dfs(int v) {
        count++;
        visited[v] = true;
        for (int w : g.getAdjacent(v))
            if (!visited[w])
                dfs(w);
    }

    public boolean isReachable(int r) {
        return visited[r];
    }

    public int getCount() {
        return count;
    }
}

