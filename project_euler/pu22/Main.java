import java.util.*;
import java.io.*;

public class Main {
	public static void main(String... args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] names = in.readLine().split("\",\"");
		names[0] = names[0].substring(1);
		names[names.length - 1] = names[names.length - 1].substring(0, names[names.length - 1].length() - 1);
		System.out.println(names[0] +" " +names[1] +" " +names[names.length - 1]);
		Arrays.sort(names);
		
		long sum = 0;
		int i = 1;	
		for(String str : names) {
			sum += code(str) * i++;
			System.out.println((i - 1) +" " +code(str) +" " +code(str)*(i - 1) +" " +str +" "+sum);
		}
		System.out.println(sum);
		
	}

	private static int code(String str) {
		int sum = 0;
		for(char c : str.toCharArray())
			sum += c - 'A' + 1;
		return sum;
	}
}
