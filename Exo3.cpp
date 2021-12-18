// commands to compile and run
// $ g++ array.cpp -o array
// $ ./array

#include <iostream>

using namespace std;

int * find_patterns(int two_D_array[5][17], int one_D_array[5] ){
    //[countPatterns,MaxSum]
    int MaxSumOfRowCorrectPattern=-1;
    int countPatterns =0;
    // print section
    int index1D =0;
    // for(int i=0;i<5;i++)
    // {
    //     for(int j=0;j<17;j++)
    //     {
    //         cout << "2D[" << i << "][" << j << "]="<<two_D_array[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0;i<5;i++){
    //      cout << "1D[" << i << "]="<<one_D_array[i]<<"\t";
    // }
    // cout << endl;
    
// Test Brutal
cout << two_D_array[4][0] %2  ;
cout << two_D_array[2][1] %2  ;


 for(int i=0;i<5;i++){
     for(int j=0;j<17;j++)
        {
            int RowSum =0;
            index1D=0;
            // fist elemnet correct
            if((two_D_array[i][j] %2 ==0 && one_D_array[index1D]==0) ||
             (two_D_array[i][j] >=0  && one_D_array[index1D]==1) ||
             (two_D_array[i][j] %3 ==0 && one_D_array[index1D]==2) ){
                //  we move index of One_D _Array to nex critaria;
                 ++index1D;
                RowSum+= two_D_array[i][j];
                //  second and third corrects
                    if((two_D_array[i][j+1] %2 ==0 && two_D_array[i][j+2] %2 ==0 && one_D_array[index1D]==0) ||
             (two_D_array[i][j+1] >=0 && two_D_array[i][j+2] >=0 && one_D_array[index1D]==1) ||
             (two_D_array[i][j+1] %3 ==0 && two_D_array[i][j+2] %3 ==0 && one_D_array[index1D]==2)){
                  ++index1D;
                RowSum+= two_D_array[i][j+1] + two_D_array[i][j+2];
            // 4th 5th & 6th are corrects
            if((two_D_array[i][j+3] %2 ==0 && two_D_array[i][j+4] %2 ==0 && two_D_array[i][j+5] %2 ==0 && one_D_array[index1D]==0) ||
             (two_D_array[i][j+3] >=0 && two_D_array[i][j+4] >=0 && two_D_array[i][j+5] >=0 && one_D_array[index1D]==1) ||
             (two_D_array[i][j+3] %3 ==0 && two_D_array[i][j+4] %3 ==0 && two_D_array[i][j+5] %3 ==0 && one_D_array[index1D]==2)){
                  ++index1D;
                RowSum+= two_D_array[i][j+3] + two_D_array[i][j+4] + two_D_array[i][j+5];
            // 7th 8th 9th 10th are corrects
              if((two_D_array[i][j+6] %2 ==0 && two_D_array[i][j+7] %2 ==0 && two_D_array[i][j+8] %2 ==0 && two_D_array[i][j+9] %2 ==0 && one_D_array[index1D]==0) ||
             (two_D_array[i][j+6] >=0 && two_D_array[i][j+7] >=0 && two_D_array[i][j+8] >=0 && two_D_array[i][j+9] >=0 && one_D_array[index1D]==1) ||
             (two_D_array[i][j+6] %3 ==0 && two_D_array[i][j+7] %3 ==0 && two_D_array[i][j+8] %3 ==0 && two_D_array[i][j+9] %3 ==0 && one_D_array[index1D]==2)){
             ++index1D;
                RowSum+= two_D_array[i][j+6] + two_D_array[i][j+7] + two_D_array[i][j+8] + two_D_array[i][j+9];
            // 11th 12th 13th 14th 15th are corrects
            if((two_D_array[i][j+10] %2 ==0 && two_D_array[i][j+11] %2 ==0 && two_D_array[i][j+12] %2 ==0 && two_D_array[i][j+13] %2 ==0  && two_D_array[i][j+14] %2 ==0 && one_D_array[index1D]==0) ||
             (two_D_array[i][j+10] >=0 && two_D_array[i][j+11] >=0 && two_D_array[i][j+12] >=0 && two_D_array[i][j+13] >=0 && two_D_array[i][j+14] >=0 && one_D_array[index1D]==1) ||
             (two_D_array[i][j+10] %3 ==0 && two_D_array[i][j+11] %3 ==0 && two_D_array[i][j+12] %3 ==0 && two_D_array[i][j+13] %3 ==0 && two_D_array[i][j+14] %3 ==0 && one_D_array[index1D]==2)){
                                //  cout << i << " : " << j  << "Final critaria OK \n";
                RowSum+= two_D_array[i][j+10] + two_D_array[i][j+11] + two_D_array[i][j+12] + two_D_array[i][j+13] +  two_D_array[i][j+14];
                ++countPatterns;
                if(RowSum > MaxSumOfRowCorrectPattern){
                    MaxSumOfRowCorrectPattern =RowSum;
                }
                // cout << MaxSumOfRowCorrectPattern << " AND countPatterns = "<<countPatterns;

             }
            
             }
            }
        }
 }
        }}


//     for (int i = 0; i < 2; ++i) {
//       cout << array_return[i] << endl;
//    }
//    cout << "Function Finished ... \n";
    static int array_return[2]={countPatterns,MaxSumOfRowCorrectPattern};
    return array_return;
}
int main()
{
 //  5 rows 17 columns
    int rows = 5, columns = 17;
    // int x[rows][17] = {};
    
    //static approach
    int x[rows][17]={
        {3,-1,3,3,3,2,3,3,3,3,3,3,3,3,3,3,3},
        {2,1,3,2,3,4,0,0,7,7,6,77,6,6,66,6,0},
        {1,-2,3,2,4,-8,252,6,7,8,9,-6,6,9,-6,9,-4},
        {1,3,5,-5,5,3,17,12,12,3,-2,5,7,9,12,66,7},
        {12,3,24,4,8,-2,12,3,3,3,3,3,3,3,3,3,3},
    };
    // set N to be 5
    int N=5;
    int set_of_rules[N] = {0,1,0,1,2};
    enum patterns_t
    {   EVEN_PT, POSITIVE_PT, DIVIDE_BY_3_MPT};

    // Scan user input array elements
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            // cout << i << " * " << j << " = ";
            // cin >> x[i][j];
        }
        cout<<endl;
    }
    // Scan user input into set_of_rules
    for(int i=0;i<N;i++)
    {
        /*
        The values in the one-dimensional array indicate the "rules" of a particular template that we want to find:
        EVEN_PT: It means even numbers.
        POSITIVE_PT: It means positive numbers (greater than zero)
        DIVIDE_BY_3_MPT: It means numbers divided by three.
        ########
        zero will indicate that he is looking for EVEN_PT,
        1 will indicate that he is looking for POSITIVE_PT,
        2 will indicate that he is looking for DIVIDE_BY_3_MPT.
        Example of input to be fed into a set of rules:
        (if we set N to be 6): 0 1 0 1 2
        */
            // cout <<"  set_of_rules[ " << i << "] = ";
            // cin >> set_of_rules[i];
        cout<<endl;
    }
    int *a = find_patterns(x,set_of_rules);
    for(int i=0; i<2; i++){
        cout << *(a + i) << endl; // you can also directly by: a[1] a[0]
    }
	return EXIT_SUCCESS;
}


/*

#16	#15	#14	#13	#12	#11	#10	#9	#8	#7	#6	#5	#4	#3	#2	#1	#0	
3	3	3	3	3	3	3	3	3	3	3	2	3	3	3	1-	3	#0
0	6	66	6	6	77	6	7	7	0	0	4	3	2	3	1	2	#1
-4	9	-6	9	6	-6	9	8	7	6	252	-8	4	2	3	-2	1	#2
7	66	12	9	7	5	2-	3	12	12	17	3	5	5-	5	3	1	#3
3	3	3	3	3	3	3	3	3	3	12	2-	8	4	24	3	12	#4




*/