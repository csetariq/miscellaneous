public class Main {
	public static void main(String... args) throws Exception {
		int limit = Integer.parseInt(args[0]);
		--limit;
		int lim3 = limit / 3;
		int lim5 = limit / 5;
		int lim15 = limit / 15;

		int sum3 = (int)((lim3 / 2.0) * (2*3 + (lim3 - 1) * 3));
		int sum5 = (int)((lim5 / 2.0) * (2*5 + (lim5 - 1) * 5));
		int sum15 = (int)((lim15 / 2.0) * (2*15 + (lim15 - 1) * 15));

		int sum = sum3 + sum5 - sum15;
		System.out.println(sum3 +" " +sum5 +" " +sum15 +" " +sum);
	}
}