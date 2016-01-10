import java.util.*;

public class Main {
    public static void main(String... args) {
        int N = (args.length == 0) ? 100 : Integer.parseInt(args[0]);
        Queue<Integer> q = new LinkedList<Integer>();
        for (int i = 1; i <= N; ++i)
            q.offer(i);
        while (q.size() != 1) {
            q.offer(q.poll());
//            System.out.print(q.poll() +" ");
            q.poll();
        }
        System.out.println(q.poll());
    }
}

