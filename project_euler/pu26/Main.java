import java.util.*;

public class Main {
	private static int cycleLength(int n) {
		List<Integer> remList = new ArrayList<Integer>();
		
		int nr = 1;
		int re = 1;
		int len = 0;
		boolean success = false;

		for(int i = 0; i < n && !success && re != 0; ++i) {
			re = nr % n;
			nr = re * 10;
			if(re != 0 && !(success = remList.contains(re)))
				remList.add(re);
		}
		if(success)
			len = remList.size() - remList.indexOf(re);
		return len;
	}

	public static void main(String... args) {
		for(int i = 1000, maxLen = 0; i > 0; --i) {
			maxLen = cycleLength(i);
			if(maxLen != i - 1)
				System.out.println(i + " " + maxLen);
			else {
				System.out.println(i +" " +maxLen +" ans");
				break;
			}
		}
	}
}
