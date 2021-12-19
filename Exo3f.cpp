//include section
	#include <iostream>
	#include <cstdlib>
		
	//using section	
	using std::cin;
	using std::cout;
	using std::endl;

// the find_pattern function
int find_patterns(int two_D_array[5][17], int set_of_rules[5] , int& MaxSumOfRowCorrectPattern ){
    int countPatterns =0;// the counter that we will return at the end
    int index1D =0; //the index used for looping set_of_rules array
 for(int i=0;i<5;i++){
     for(int j=0;j<17;j++)
        {
            int RowSum =0;// initiate Sum of current Row  [i]
            index1D=0; //set to cursor on first element of set_of_rules
            // if fist element is correct
            if((two_D_array[i][j] %2 ==0 && set_of_rules[index1D]==0) ||
             (two_D_array[i][j] >=0  && set_of_rules[index1D]==1) ||
             (two_D_array[i][j] %3 ==0 && set_of_rules[index1D]==2) ){
                
                 ++index1D;//  we move index of One_D _Array to next critaria
                RowSum+= two_D_array[i][j];//add this element tested to Sum of Row
                // if second and third are corrects
                    if((two_D_array[i][j+1] %2 ==0 && two_D_array[i][j+2] %2 ==0 && set_of_rules[index1D]==0) ||
             (two_D_array[i][j+1] >=0 && two_D_array[i][j+2] >=0 && set_of_rules[index1D]==1) ||
             (two_D_array[i][j+1] %3 ==0 && two_D_array[i][j+2] %3 ==0 && set_of_rules[index1D]==2)){
                  ++index1D;
                RowSum+= two_D_array[i][j+1] + two_D_array[i][j+2];
            // if 4th 5th & 6th are corrects
            if((two_D_array[i][j+3] %2 ==0 && two_D_array[i][j+4] %2 ==0 && two_D_array[i][j+5] %2 ==0 && set_of_rules[index1D]==0) ||
             (two_D_array[i][j+3] >=0 && two_D_array[i][j+4] >=0 && two_D_array[i][j+5] >=0 && set_of_rules[index1D]==1) ||
             (two_D_array[i][j+3] %3 ==0 && two_D_array[i][j+4] %3 ==0 && two_D_array[i][j+5] %3 ==0 && set_of_rules[index1D]==2)){
                  ++index1D;
                RowSum+= two_D_array[i][j+3] + two_D_array[i][j+4] + two_D_array[i][j+5];
            // if 7th 8th 9th 10th are corrects
              if((two_D_array[i][j+6] %2 ==0 && two_D_array[i][j+7] %2 ==0 && two_D_array[i][j+8] %2 ==0 && two_D_array[i][j+9] %2 ==0 && set_of_rules[index1D]==0) ||
             (two_D_array[i][j+6] >=0 && two_D_array[i][j+7] >=0 && two_D_array[i][j+8] >=0 && two_D_array[i][j+9] >=0 && set_of_rules[index1D]==1) ||
             (two_D_array[i][j+6] %3 ==0 && two_D_array[i][j+7] %3 ==0 && two_D_array[i][j+8] %3 ==0 && two_D_array[i][j+9] %3 ==0 && set_of_rules[index1D]==2)){
             ++index1D;
                RowSum+= two_D_array[i][j+6] + two_D_array[i][j+7] + two_D_array[i][j+8] + two_D_array[i][j+9];
            // if 11th 12th 13th 14th 15th are corrects
            if((two_D_array[i][j+10] %2 ==0 && two_D_array[i][j+11] %2 ==0 && two_D_array[i][j+12] %2 ==0 && two_D_array[i][j+13] %2 ==0  && two_D_array[i][j+14] %2 ==0 && set_of_rules[index1D]==0) ||
             (two_D_array[i][j+10] >=0 && two_D_array[i][j+11] >=0 && two_D_array[i][j+12] >=0 && two_D_array[i][j+13] >=0 && two_D_array[i][j+14] >=0 && set_of_rules[index1D]==1) ||
             (two_D_array[i][j+10] %3 ==0 && two_D_array[i][j+11] %3 ==0 && two_D_array[i][j+12] %3 ==0 && two_D_array[i][j+13] %3 ==0 && two_D_array[i][j+14] %3 ==0 && set_of_rules[index1D]==2)){
                //  Here the Pattern is Found
                // we add last elements to Sum
                RowSum+= two_D_array[i][j+10] + two_D_array[i][j+11] + two_D_array[i][j+12] + two_D_array[i][j+13] +  two_D_array[i][j+14];
                ++countPatterns; //we increment our counter of pattern
                if(RowSum > MaxSumOfRowCorrectPattern){
                    MaxSumOfRowCorrectPattern =RowSum; //we make sure that we will have the max Sum of rows
                }
             }
             }
            }
        }
 }
        }
        }
    return countPatterns;
}
//main section
int main()
{
 //  5 rows 17 columns
    int rows = 5, columns = 17;
    // define the two D array
    int matrix[rows][17] = {};
    // set N to be 5
    int N=5;
    int set_of_rules[N] = {0,1,0,1,2};
    // Scan user input for 2d array [Matrix]
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout << i << " * " << j << " = ";
            cin >> matrix[i][j];
        }
        cout<<endl;
    }
    // Scan user input into set_of_rules
    for(int i=0;i<N;i++)
    {
            cout <<"  set_of_rules[ " << i << "] = ";
            cin >> set_of_rules[i];
        cout<<endl;
    }
    // Define the reference parrametter
    int MaxSumOfRowCorrectPattern{ -1 };
    // call find_patterns function
    int countPatterns = find_patterns(matrix,set_of_rules,MaxSumOfRowCorrectPattern);
    // print the result
    cout << countPatterns <<" "<< MaxSumOfRowCorrectPattern<<endl;
	return EXIT_SUCCESS;
}