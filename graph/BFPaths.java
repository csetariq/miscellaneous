import java.util.*;

public class BFPaths {
    private Graph g;
    private int s;
    private boolean[] visited;
    private int[] edgeTo;
    private int[] distTo;
    int count;

    public BFPaths(Graph g, int s) {
        this.g = g;
        this.s = s;
        visited = new boolean[g.V()];
        edgeTo = new int[g.V()];
        distTo = new int[g.V()];
        bfs(s);
    }

    private void bfs(int x) {
        count++;
        Queue<Integer> q = new LinkedList<Integer>();
        q.offer(x);
        while (!q.isEmpty()) {
            int v = q.poll();
            visited[v] = true;
            for (int w : g.getAdjacent(v))
                if (!visited[w]) {
                    q.offer(w);
                    visited[w] = true;
                    edgeTo[w] = v;
                    distTo[w] = distTo[v] + 1;
                }
        }
    }

    public boolean isReachable(int r) {
        return visited[r];
    }

    public int getCount() {
        return count;
    }

    public int getDistTo(int x) {
        return distTo[x];
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
        
        BFPaths path = new BFPaths(g, 3);
        for (int x : path.getPathTo(8))
            System.out.println(x + " ");
        System.out.println("dist to " + 8 + " " + path.getDistTo(8));

        for (int x : path.getPathTo(0))
            System.out.println(x + " ");
        System.out.println("dist to " + 0 + " " + path.getDistTo(0));

        for (int x : path.getPathTo(5))
            System.out.println(x + " ");
        System.out.println("dist to " + 5 + " " + path.getDistTo(5));
    }
}

