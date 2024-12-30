public class problem_6{
	public static void main(String[] args){
		compress("aabcccaaa"); 
		compress("aabcAAAaaa"); 
		compress("aabCCCCaaa"); 
		compress("aabcccAAAA"); 
		compress("aabcccaaa"); 
	
	}

	static void compress(String s){
		char temp=' ';
		char[] words = s.toCharArray();
		int count=0;
		StringBuilder sb = new StringBuilder();
		boolean first = false;

		for (int i = 0; i < words.length; i++) {
			if(temp!=words[i]){
					if(first){
					sb.append(count);
					count=0;
					}

				temp=words[i];
				sb.append(temp);
				first=true;
				count++;
			}
			else{
			count++;
			}
			if(i==words.length-1)
				sb.append(count);
		}
		if(sb.length()<s.length())
		System.out.println(sb);
		else
		System.out.println(s);
	}

}

