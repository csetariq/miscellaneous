import java.util.*;

public class Main {
    public static void main(String... args) {
        Queue<Integer> q = new LinkedList<Integer>();
        for (int i = 1; i <= 100; ++i)
            q.offer(i);
        while (q.size() != 1) {
            q.offer(q.poll());
            System.out.print(q.poll() +" ");
        }
        System.out.println(q.poll());
    }
}

