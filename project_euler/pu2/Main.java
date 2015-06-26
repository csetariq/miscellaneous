public class Main {
	public static void main(String... args) throws Exception {
		int limit = Integer.parseInt(args[0]);
		int x = 1;
		int y = 2;
		long sum = y;
		do {
			int naya = x + y;
			x = y;
			y = naya;
			if((naya & 1) == 0)
				sum += naya;
		} while(y < limit;
		System.out.println(sum);		
	}
}