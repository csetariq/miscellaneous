public class Main {

	public static void main(String... args) {
		int n = Integer.parseInt(args[0]);
		
		int sumSq = n * (n + 1) / 2;
		sumSq *= sumSq;
		
		int sqSum = n * (n + 1) * (2 * n + 1) / 6;

		System.out.println(sumSq - sqSum);
	}
}