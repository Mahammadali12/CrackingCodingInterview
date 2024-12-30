public class problem_3{

	public static void main(String[] args){
		URLify("Mr John Smith    ",13);
	}
	
	static void URLify(String s, int true_length){
		char res[] = new char [s.length()];
		char [] w = s.toCharArray();
		int idx=0;

		for (int index = 0; index < s.length(); index++) {
			if(w[idx] != ' '){
				res[index]=w[idx];
				idx++;
			}	
			else{
				res[index]='%';
				res[++index]='2';
				res[++index]='0';
				idx++;
			}
			if(idx>=true_length)
				break;

		}

			System.out.println(new String(res));
	}
}
