/**
*	Permutator program.
*	Running time - O(set.length^(length+1))
*
*/

public class Main {
	
	private static int count;
	private static int length;
	
	public static void main(String[] args) {
		length = 3;
		char[] set = {'1', '2', '3'};
		char[] str = new char[length];

		permute(set, str, 0);
		//System.out.println(count);
	}

	private static void permute(char[] set, char[] str, int level) {
		//++count;
		if(level < length) {
			for(char c : set) {
				str[level] = c;
				permute(set, str, level + 1);
			}
		}
		else {
			System.out.println(new String(str, 0, str.length));
		}
	}
}
