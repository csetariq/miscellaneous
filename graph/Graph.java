import java.util.*;

public interface Graph {

    public int V();
    public int E();
    public void addEdge(int v, int w);
    public Iterable<Integer> getAdjacent(int v);
}

