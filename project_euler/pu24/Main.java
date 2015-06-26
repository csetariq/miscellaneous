import java.util.*;

public class Main {
	public static void main(String... args) {
		int n = Integer.parseInt(args[0]) - 1;
		List<Integer> set = new LinkedList<Integer>();
		set.add(0);
		set.add(1);
		set.add(2);
		set.add(3);
		set.add(4);
		set.add(5);
		set.add(6);
		set.add(7);
		set.add(8);
		set.add(9);

		for(int i = set.size() - 1; i >= 0; --i) {
			int facti = fact(i);
			int itemIdx = n / facti;
			int item = set.get(itemIdx);
			System.out.print(item);
			set.remove(new Integer(item));
			n %= facti;
		}
	}

	private static int fact(int n) {
		if(n == 0 || n == 1)
			return 1;
		return n * fact(n - 1);
	}
}
