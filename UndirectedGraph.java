import java.util.*;

public class UndirectedGraph implements Graph {
    private int V;
    private int E;
    private Set<Integer>[] adj;

    @SuppressWarnings("unchecked")
    public UndirectedGraph(int V) {
        this.V = V;
        adj = (Set<Integer>[]) new Set[V];
        for (int i = 0; i < V; ++i)
            adj[i] = new LinkedHashSet<Integer>();
    }

    public int V() {
        return V;
    }

    public int E() {
        return E;
    }

    public void addEdge(int v, int w) {
        E++;
        adj[v].add(w);
        adj[w].add(v);
    }

    public Iterable<Integer> getAdjacent(int v) {
        return adj[v];
    }

    public String toString() {
        final String NEWLINE = System.lineSeparator();
        StringBuilder sb = new StringBuilder();
        sb.append("Number of Vertices: ");
        sb.append(V);
        sb.append(NEWLINE);
        sb.append("Number of Edges: ");
        sb.append(E);
        sb.append(NEWLINE);
        sb.append(NEWLINE);
        for (int i = 0; i < V; ++i) {
            for (int neighbour : adj[i]) {
                sb.append(i);
                sb.append(" - ");
                sb.append(neighbour);
                sb.append(NEWLINE);
            }
        }
        return sb.toString();
    }
}

