public class Main {
	public static void main(String... args) throws Exception {
		int limit = Integer.parseInt(args[0]);
		int[] factors = new int[limit];
		
		for(int i = 0; i < factors.length; ++i)
			factors[i] = i + 1;

		boolean allOne = false;
		boolean noDiv = false;
		int max = limit;
		int lcm = 1;
		
		for(int i = 2; i <= max && !allOne; ) {
			allOne = true;
			noDiv = false;
			int temp_max = Integer.MIN_VALUE;
			for(int j = 0; j < factors.length; ++j) {
				if(factors[j] % i == 0) {
					int quot = factors[j] / i;
					factors[j] = quot;
					noDiv = true;

					
				}
				if(factors[j] != 1)
					allOne = false;
				if(temp_max < factors[j])
					temp_max = factors[j];
			}
			
			max = temp_max;
			
			if(noDiv) {
				lcm *= i;
				System.out.println(i +" " +max);
			} else {
				++i;
			}
			for(int x : factors)
				System.out.print(" " +x);
			System.out.println();
			
		}
		System.out.println(lcm);
	}
}