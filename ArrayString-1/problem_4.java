public class problem_4{

	public static void main(String[] args){
		System.out.println(isPalindrome("Ta ctCoa"));	
		System.out.println(isPalindrome("aabbccdde"));	
		System.out.println(isPalindrome("aabbccdd"));	
		System.out.println(isPalindrome("aabbccddeeff"));	
		System.out.println(isPalindrome("slsaa"));	
	}

	static boolean isPalindrome(String s){
		int[] words = new int[26];
		char[] chars = s.toLowerCase().toCharArray();
		int odd_count=0;
		for(int i=0;i<chars.length;i++){
			if(chars[i]!=' ')
			words[chars[i]-'a']++;
		}

		for(int ii : words){
			if(ii%2==1)
				odd_count++;
			if(odd_count>1)
				return false;
		}
		return true;
	}


}
