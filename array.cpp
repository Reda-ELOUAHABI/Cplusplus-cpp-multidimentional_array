// reda@ELOUAHABI:/mnt/c/Users/Reda El Ouahabi/Desktop/mvn_proj/cplus$ g++ array.cpp -o array
// reda@ELOUAHABI:/mnt/c/Users/Reda El Ouahabi/Desktop/mvn_proj/cplus$ ./array

#include <iostream>

using namespace std;

void FirstExo(){
    cout<<"First Exo\n";
    int rows = 4 , columns=5;
    // an array with 4 rows and 5 columns.
    int x[rows][columns] = {};
    // int x[3][2] = {{0,1}, {2,3}, {4,5}};
    // since all elements are positive
    int maxRowSumIndex=0,maxColmnSumIndex=0;
    int RowSum=0,ColmnSum=0;
    // output each array element's value + findRow Max
    for (int i = 0; i < rows; i++)
    {
        int SumR=0;
        for (int j = 0; j < columns; j++)
        {
            cout << "Element at x[" << i
                 << "][" << j << "]: ";
            // Another way to insert a new line, is with the endl manipulator: == \n\n 
            cin >> x[i][j];
            SumR+= x[i][j];
            cout << x[i][j]<<endl;
        }
        if(SumR>RowSum){
            RowSum=SumR;
            maxRowSumIndex=i;
            SumR =0;
        }
        else{
            SumR =0;
        }
    }
    // Find the maximum on Columns
    for (int i = 0; i < columns; i++)
    {
        int SumC=0;
        for (int j = 0; j < rows; j++)
        {
            SumC+= x[j][i];
        }
        if(SumC>ColmnSum){
            ColmnSum=SumC;
            maxColmnSumIndex=i;
            SumC =0;
        }
         else{
            SumC =0;
        }
    }
    cout << "Row Sum " << RowSum << " its index = " << maxRowSumIndex;
    cout << "Column Sum " << ColmnSum << " its index = " << maxColmnSumIndex;
}

void SecondExo(){
    cout<<"Second Exo\n";
    int rows = 10 , columns=15;
    int x[rows][columns] = {
        { 0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  9,  9,  9,  9,  9,  9},
        { 0,  0,  13, 0,  0,  0,  0,  0,  0,  0,  9,  0,  0,  0,  9,  0},
        { 0,  13, 0,  13, 0,  0,  0,  0,  0,  0,  0,  9,  0,  9,  0,  0},
        { 13, 13, 13, 13, 13, 13, 13, 13, 13, 0,  0,  0,  9,  0,  0,  0},
        { 0,  13, 0,  0,  0,  0,  0,  13, 0,  0,  0,  9,  0,  9,  0,  0},
        { 0,  0,  13, 0,  0,  0,  13, 17, 0,  0,  9,  9,  9,  9,  9,  0},
        { 0,  0,  0,  13, 0,  13, 17, 0,  17, 9,  9,  9,  9,  9,  9,  9},
        { 0,  0,  0,  0,  13, 17, 0,  0,  0,  17, 0,  0,  0,  0,  0,  0},
        { 0,  0,  0,  0,  17, 0,  0,  0,  0,  0,  17, 0,  0,  0,  0,  0},
        { 0,  0,  0,  17, 17, 17, 17, 17, 17, 17, 17, 17,  0,  0,  0,  0},
        { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},

    };
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Element at x[" << i
           << "][" << j << "]: ";
            cin >> x[i][j];
        }
    }
}
int main()
{
    FirstExo();
    return 0;
}
