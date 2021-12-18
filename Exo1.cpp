// commands to compile and run
// $ g++ array.cpp -o array
// $ ./array

#include <iostream>

using namespace std;

// static approach
void FirstExoStatic()
{
    cout << "First Exo with static approach \n";
     // an array with 4 rows and 5 columns.
    int rows = 4, columns = 5;
    // static approach
    int x[rows][columns] = {{0,1,2,3,4}, {1,2,3,4,5}, {2,3,4,5,6}, {2,3,4,5,6}};
    // since all elements are positive
    int maxRowSumIndex = 0, maxColmnSumIndex = 0;
    int RowSum = 0, ColmnSum = 0;
    // output each array element's value + findRow Max
    for (int i = 0; i < rows; i++)
    {
        int SumR = 0;
        for (int j = 0; j < columns; j++)
        {
            SumR += x[i][j];
        }
        if (SumR > RowSum)
        {
            RowSum = SumR;
            maxRowSumIndex = i;
            SumR = 0;
        }
        else
        {
            SumR = 0;
        }
    }
    // Find the maximum on Columns
    for (int i = 0; i < columns; i++)
    {
        int SumC = 0;
        for (int j = 0; j < rows; j++)
        {
            SumC += x[j][i];
        }
        if (SumC > ColmnSum)
        {
            ColmnSum = SumC;
            maxColmnSumIndex = i;
            SumC = 0;
        }
        else
        {
            SumC = 0;
        }
    }
    cout << "Row Sum = " << RowSum << " its index = " << maxRowSumIndex << endl;
    cout << "Column Sum " << ColmnSum << " its index = " << maxColmnSumIndex;
}

//dynamic approach
void FirstExoDynamic()
{
    cout << "First Exo  with dynamic approach \n";
     // an array with 4 rows and 5 columns.
    int rows = 4, columns = 5;
    // dynamic approach
    int x[rows][columns] = {};
    // since all elements are positive
    int maxRowSumIndex = 0, maxColmnSumIndex = 0;
    int RowSum = 0, ColmnSum = 0;
    // output each array element's value + findRow Max
    for (int i = 0; i < rows; i++)
    {
        int SumR = 0;
        for (int j = 0; j < columns; j++)
        {
            cout << "Enter Element x[" << i
                 << "][" << j << "]: ";
            //  dynamic approach
            cin >> x[i][j];
            SumR += x[i][j];
            cout << x[i][j] << endl;
        }
        if (SumR > RowSum)
        {
            RowSum = SumR;
            maxRowSumIndex = i;
            SumR = 0;
        }
        else
        {
            SumR = 0;
        }
    }
    // Find the maximum on Columns
    for (int i = 0; i < columns; i++)
    {
        int SumC = 0;
        for (int j = 0; j < rows; j++)
        {
            SumC += x[j][i];
        }
        if (SumC > ColmnSum)
        {
            ColmnSum = SumC;
            maxColmnSumIndex = i;
            SumC = 0;
        }
        else
        {
            SumC = 0;
        }
    }
    cout << "The final result of program is \n\n" ;
    cout << "Row Sum " << RowSum << " its index = " << maxRowSumIndex << endl;
    cout << "Column Sum " << ColmnSum << " its index = " << maxColmnSumIndex;
}

int main()
{
    int userInput;
    do {
        cout << "\n\n";
        cout << "for static approach entrer \t 1 \n for dynmamic approach enter \t 2 \n for EXIT enter \t 0 " << endl;
        cin >> userInput;
        cout << "\n\n";
        if(userInput==1){
            FirstExoStatic();
        }
        else if (userInput == 2){
            FirstExoDynamic();
        }
}
while (userInput != 0);
 cout << "EXIT ...";
    return 0;
}

