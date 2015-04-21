public class Main {
	public static void main(String... args) throws Exception {
		//int limit = Integer.parseInt(args[0]);
		int max = Integer.MIN_VALUE;
		for(int i = 999; i > 0; --i) {
			for(int j = 999; j > 0; --j)
				if(isPalindrome(i * j))
					if(max < (i * j))
						max = i * j;
		}
		System.out.println(max);
	}
	
	private static boolean isPalindrome(int num) {
		return new StringBuilder(String.valueOf(num)).reverse().toString().equals(String.valueOf(num));
	}
}