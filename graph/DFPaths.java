import java.util.*;

public class DFPaths {
    private Graph g;
    private int s;
    private boolean[] visited;
    private int[] edgeTo;
    int count;

    public DFPaths(Graph g, int s) {
        this.g = g;
        this.s = s;
        visited = new boolean[g.V()];
        edgeTo = new int[g.V()];
        dfs(s);
    }

    private void dfs(int v) {
        count++;
        visited[v] = true;
        for (int w : g.getAdjacent(v))
            if (!visited[w]) {
                edgeTo[w] = v;
                dfs(w);
            }
    }

    public boolean isReachable(int r) {
        return visited[r];
    }

    public int getCount() {
        return count;
    }

    public Iterable<Integer> getPathTo(int x) {
        if (!visited[x]) return null;

        Stack<Integer> path = new Stack<Integer>();
        for (int i = x; i != s; i = edgeTo[i]) {
            path.push(i);
        }
        path.push(s);

        return path;
    }
    
    public static void main(String... args) {
        Graph g = new UndirectedGraph(10);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 5);
        g.addEdge(2, 3);
        g.addEdge(2, 4);
        g.addEdge(5, 6);
        g.addEdge(3, 6);
        g.addEdge(6, 7);
        g.addEdge(7, 8);
        g.addEdge(7, 9);
        
        DFPaths path = new DFPaths(g, 5);
        for (int x : path.getPathTo(8))
            System.out.println(x + " ");
    }
}

