public class Driver {
    public static void main(String... args) {
        Graph g = new UndirectedGraph(7);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(0, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 3);
        g.addEdge(3, 4);
        g.addEdge(5, 6);
        System.out.println(g);

        DFSearch dfs = new DFSearch(g, 0);
        System.out.println("Reachable vertices " + dfs.getCount());
        System.out.println(dfs.isReachable(0));
        System.out.println(dfs.isReachable(1));
        System.out.println(dfs.isReachable(2));
        System.out.println(dfs.isReachable(3));
        System.out.println(dfs.isReachable(4));
        System.out.println(dfs.isReachable(5));
        System.out.println(dfs.isReachable(6));

        dfs = new DFSearch(g, 5);
        System.out.println("Reachable vertices " + dfs.getCount());
        System.out.println(dfs.isReachable(0));
        System.out.println(dfs.isReachable(1));
        System.out.println(dfs.isReachable(2));
        System.out.println(dfs.isReachable(3));
        System.out.println(dfs.isReachable(4));
        System.out.println(dfs.isReachable(5));
        System.out.println(dfs.isReachable(6));
    }
}

