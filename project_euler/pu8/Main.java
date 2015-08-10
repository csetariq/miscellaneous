public class Main {

	public static void main(String... args) throws Exception {
        int len = Integer.parseInt(args[0]);
		int[] num = new int[1000];
		int ptr = 0;

		int temp = 0;
		while((temp = System.in.read()) != -1) {
			if(temp != '\r' && temp != '\n') {
				//System.out.print(temp - '0');
				num[ptr++] = temp - '0';
			}
		}

		long maxProd = Integer.MIN_VALUE;
		for(int i = 0; i <= ptr - len; ++i) {
			long prod = 1;
			for(int j = i; j < i + len; ++j)
				prod *= num[j];
			if(prod > maxProd)
				maxProd = prod;
		}
		System.out.println(maxProd);
	}
}
