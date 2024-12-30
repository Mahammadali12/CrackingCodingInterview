public class problem_2{
 	public static void main(String[] args){
		System.out.print(permutation("permutation","permut")+"\n");
		System.out.print(permutation("permutation","permutation")+"\n");
		System.out.print(permutation("permutation","perm")+"\n");
		System.out.print(permutation("permutation","permuta")+"\n");
		System.out.print(permutation("permutation","permutyas")+"\n");
	}

	static boolean permutation(String main, String per){
		char[] mainChar = main.toCharArray();
		char[] perChar = per.toCharArray();

		int[] mainC = new int[26];
		int[] perC = new int[26];
		
		for (int i = 0; i < mainChar.length; i++) {
			mainC[mainChar[i]-'a']++;
		}
		for (int i = 0; i < perChar.length; i++) {

			perC[perChar[i]-'a']++;
		}

		for (int index = 0; index < 26; index++) {
			if((mainC[index] - perC[index]) <0)
				return false;
		}
		return true;
	}



}
