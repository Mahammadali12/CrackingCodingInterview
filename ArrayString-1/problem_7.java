public class problem_7{
	public static void main(String[] args){
		int [][] temp = new int [5][5];
		initialize(temp);	
			System.out.println();
			System.out.println();
			System.out.println();
		rotate(temp);
	}

	static void initialize(int[][] init){
		int number = 0;
		for(int i=0;i<init.length;i++){
			for(int j=0; j<(init[0].length);j++){
				init[i][j]=number;		
				number++;
				System.out.print(init[i][j]+" ");
			}
			System.out.println();
		}
	}

	static void rotate(int[][] init){
		int[] [] neww = new int [init.length][init[0].length];
		for(int i =0; i<init.length;i++){
			for(int j=0; j<init[0].length;j++){
				neww[i][j]=init[j][init.length-i-1];
				System.out.print(neww[i][j]+" ");
			}
				System.out.println();
		}
	}
}
