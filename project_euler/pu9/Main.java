public class Main  {
	public static void main(String... args) {
		
		for(int a = 1; a < 333; ++a)
			for(int b = a + 1; b <= (1000 - a); ++b)
				for(int c = b + 1; c <= (1000 - a - b); ++c) {
					if((a + b + c) == 1000) {
						int a2 = a * a;
						int b2 = b * b;
						int c2 = c * c;

						if(a2 + b2 == c2)
							System.out.println(a +" " +b +" " +c +" " + a * b * c);
					}
				}
	}
}