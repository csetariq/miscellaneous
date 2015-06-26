import java.util.Arrays;

public class Main {

	public static void main(String... args) {
		final int MAX = (int)Math.pow(2, 20);
		//int n = Integer.parseInt(args[0]);

		boolean[] primes = new boolean[MAX];
		Arrays.fill(primes, true);

		primes[0] = primes[1] = false;
		
		for(int i = 2; i < primes.length; ++i)
			for(int j = i + i; j < primes.length; j += i)
				primes[j] = false;

		int count = 0;
		for(int i = 2; i < primes.length; ++i)
			if(primes[i]) {
				System.out.println(i +" " + ++count);
				if(count == 10001)
					System.err.println(i);
			}
	}
}