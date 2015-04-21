public class Main {
	public static void main(String... args) {
		long x = Long.parseLong(args[0]);
		long y = Long.parseLong(args[1]);
		long max = Integer.MIN_VALUE;
		long max_num = Integer.MIN_VALUE;
		for(long i = x; i <= y; ++i) {
			//System.out.println("processing " +i);
			long temp = i;
			long count = 1;
			//System.out.print(temp +" ");
			while(temp != 1) {
				if((temp & 1) == 1)
					temp = temp * 3 + 1;
				else
					temp >>= 1;
				++count;				
				//System.out.print(temp +" ");
			}
			if(max < count) {
				max = count;
				max_num = i;
				System.out.println(max_num +" > " +max);
			}
		}		
	}
}