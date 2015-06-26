public class Main {
	public static void main(String... args) throws Exception {
		Long num = Long.parseLong(args[0]);
		for(long i = 2; i <= num / 2; ++i) {
			if(num % i == 0)
				if(isPrime(i)) {
					System.out.println(i);
					num /= i;
				}
		}
		System.out.println(num);
	}
		
	private static boolean isPrime(long number) {
		long lim = (long)Math.sqrt(number);
		for(long i = 2; i <= lim; ++i)
			if(number % i == 0)
				return false;
		return true;
	}
}