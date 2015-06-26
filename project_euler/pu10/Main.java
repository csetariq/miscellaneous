import java.util.Arrays;

public class Main {

	public static void main(String... args) {
		final int MAX = 2_000_000;
		//int n = Integer.parseInt(args[0]);

		boolean[] primes = new boolean[MAX];
		Arrays.fill(primes, true);

		primes[0] = primes[1] = false;
		
		for(int i = 2; i < primes.length; ++i)
			for(int j = i + i; j < primes.length; j += i)
				primes[j] = false;

		long sum = 0;
		for(int i = 2; i < primes.length; ++i)
			if(primes[i]) {
				sum += i;
			}
		System.err.println(sum);
	}
}