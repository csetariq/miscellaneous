import java.math.BigInteger;
import java.io.*;

public class Main {
	public static void main(String... args) throws Exception {
		BigInteger sum = BigInteger.ZERO;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i = 0; i < 100; ++i) {
			sum = sum.add(new BigInteger(br.readLine()));
		}
		System.out.println(sum);
	}
}