public class Main {

	public static void main(String... args) throws Exception {
		int[] num = new int[1000];
		int ptr = 0;

		int temp = 0;
		while((temp = System.in.read()) != -1) {
			if(temp != '\r' && temp != '\n') {
				//System.out.print(temp - '0');
				num[ptr++] = temp - '0';
			}
		}

		int maxProd = Integer.MIN_VALUE;
		for(int i = 0; i <  1000 - 5; ++i) {
			int prod = 1;
			for(int j = i; j < i + 5; ++j)
				prod *= num[j];
			if(prod > maxProd)
				maxProd = prod;
		}
		System.out.println(maxProd);
	}
}