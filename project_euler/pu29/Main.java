import java.math.*;
import java.util.*;

public class Main {
	private static final int MAX = 100;
	private static final BigInteger BMAX = new BigInteger(String.valueOf(MAX));
	public static void main(String... args) {
		Set<BigInteger> unique = new HashSet<BigInteger>();
		int cnt = 0;
		for(BigInteger i = new BigInteger("2"); i.compareTo(BMAX) <= 0; i = i.add(BigInteger.ONE)) {
			for(int j = 2; j <= MAX; ++j) {
				if(unique.add(i.pow(j))) {
					++cnt;
					System.out.println(cnt);
				}
			}
		}
		System.out.println(cnt);
	}
}
