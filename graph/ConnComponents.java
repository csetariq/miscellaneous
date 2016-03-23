
public class ConnComponents {
    private Graph g;
    private boolean[] visited;
    private int[] id;
    private int[] size;
    private int count;

    public ConnComponents(Graph g) {
        this.g = g;
        visited = new boolean[g.V()];
        id = new int[g.V()];
        size = new int[g.V()];
        for (int i = 0; i < g.V(); ++i) {
            if (!visited[i]) {
                ++count;
                dfs(i);
            }
        }
    }

    private void dfs(int v) {
        size[count]++;
        visited[v] = true;
        id[v] = count;
        for (int w : g.getAdjacent(v))
            if (!visited[w])
                dfs(w);
    }

    public int getCount() {
        return count;
    }

    public int getId(int v) {
        return id[v];
    }

    public int getSize(int id) {
        return size[id];
    }

    public static void main(String... args) {
        Graph g = new UndirectedGraph(9);
        g.addEdge(0, 1);
        g.addEdge(0, 3);
        g.addEdge(3, 4);
        g.addEdge(2, 4);
        g.addEdge(5, 7);
        g.addEdge(5, 6);

        ConnComponents c = new ConnComponents(g);
        System.out.println("total connected components " + c.getCount());
        for (int i = 1; i <= c.getCount(); ++i)
            System.out.println("size of " + i + " " + c.getSize(i));
        for (int i = 0; i < g.V(); ++i)
            System.out.println("id of " + i + " " + c.getId(i));
            
    }


}

