//include section
	#include <iostream>
	#include <cstdlib>
		
	//using section	
	using std::cin;
	using std::cout;
	using std::endl;
	
	//main section
	int main()
	{
		int max_row = 0;// to help find the index of the row that give the maximum value of the sum
		int row_sum = 0;// to calculate the sum of each row
		int row_ind;// the index of the row
		int max_col = 0;// to help fing the index of the col that gives the maximum value of the sum
		int col_sum = 0;// to calculate the sum of each col
		int col_ind;// the index of the col
		
		const int R = 4;// number of rows
		const int C = 5;// number of cols
		int arr[R][C];
		
		// this loop calculates the sum of each row in the matrix then returns in the end the index of the maximum row value 
		for (int i = 0 ; i < R ; i++)
		{	
			for (int j = 0 ; j < C ; j++)
			{
				cin >> arr[i][j];
				
				row_sum += arr[i][j];
			}
			if (row_sum > max_row)
			{
				max_row = row_sum;
				row_ind = i;
			}
			row_sum = 0;
		}
		// this loop calculates the sum of each col in the matrix then returns in the end the index of the maximum col value 
		for (int p = 0 ; p < C ; p++)
		{
			for (int q = 0; q < R ; q++)
			{
				cin >> arr[q][p];
				col_sum += arr[q][p];
			}
			if (col_sum > max_col)
			{
				max_col = col_sum;
				col_ind = p;
			}
			col_sum = 0;
		}
		// printing the index of the maximum row and the index of the maximum col
		cout << row_ind << " " << col_ind << endl;
		
		return EXIT_SUCCESS;
	}