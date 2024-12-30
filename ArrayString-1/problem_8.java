public class problem_8{	

	public static void main(String [] args){

	int [] []arr = {{1,0,4,5},
			{2,4,5,6},
			{31,1,23,432},
			{2,0,432,12},
			{1,2,3,4}};
	boolean[] rows = new boolean[arr.length];
	boolean[] columns = new boolean[arr[0].length];

		find_zeros(arr,rows,columns);
		zero_columns(arr,rows);
		zero_rows(arr,columns);
				
		for(int i =0; i<rows.length;i++){
			for(int j = 0 ;j<columns.length;j++){
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
	
	}
	static void find_zeros(int[] [] arr,boolean[] rows,boolean[] columns){
		for(int i = 0 ; i<rows.length;i++){
			for(int j = 0 ; j<columns.length;j++){
				if(arr[i][j]==0){
					rows[i]=true;
					columns[j]=true;
				}
			}
		}
	}
	
	static void zero_columns(int[] [] arr,boolean[] rows){
		for(int i = 0 ;i<rows.length;i++){
			if(rows[i]){
				for(int column = 0;column<arr[0].length;column++)
					arr[i][column]=0;
			}
		}
	}

	static void zero_rows(int[] [] arr, boolean[] columns){
		for(int i = 0; i < columns.length; i++){
			if(columns[i]){
				for(int row = 0 ; row < arr.length;row++)
					arr[row][i]=0;
			}
		}
	}

}
