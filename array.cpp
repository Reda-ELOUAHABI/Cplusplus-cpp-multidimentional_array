// reda@ELOUAHABI:/mnt/c/Users/Reda El Ouahabi/Desktop/mvn_proj/cplus$ g++ array.cpp -o array
// reda@ELOUAHABI:/mnt/c/Users/Reda El Ouahabi/Desktop/mvn_proj/cplus$ ./array

#include <iostream>

using namespace std;

void FirstExo()
{
    cout << "First Exo\n";
    int rows = 4, columns = 5;
    // an array with 4 rows and 5 columns.
    int x[rows][columns] = {};
    // int x[3][2] = {{0,1}, {2,3}, {4,5}};
    // since all elements are positive
    int maxRowSumIndex = 0, maxColmnSumIndex = 0;
    int RowSum = 0, ColmnSum = 0;
    // output each array element's value + findRow Max
    for (int i = 0; i < rows; i++)
    {
        int SumR = 0;
        for (int j = 0; j < columns; j++)
        {
            cout << "Element at x[" << i
                 << "][" << j << "]: ";
            // Another way to insert a new line, is with the endl manipulator: == \n\n
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
    cout << "Row Sum " << RowSum << " its index = " << maxRowSumIndex;
    cout << "Column Sum " << ColmnSum << " its index = " << maxColmnSumIndex;
}

// reda@ELOUAHABI:/mnt/c/Users/Reda El Ouahabi/Desktop/mvn_proj/cplus$ g++ array.cpp -o array
// reda@ELOUAHABI:/mnt/c/Users/Reda El Ouahabi/Desktop/mvn_proj/cplus$ ./array

void SecondExo()
{
    cout << "Second Exo\n";
    int rows = 10, columns = 15;
    int x[rows][columns] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9},
        {0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 9, 0},
        {0, 13, 0, 13, 0, 0, 0, 0, 0, 0, 0, 9, 0, 9, 0, 0},
        {13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 9, 0, 0, 0},
        {0, 13, 0, 0, 0, 0, 0, 13, 0, 0, 0, 9, 0, 9, 0, 0},
        {0, 0, 13, 0, 0, 0, 13, 17, 0, 0, 9, 9, 9, 9, 9, 0},
        {0, 0, 0, 13, 0, 13, 17, 0, 17, 9, 9, 9, 9, 9, 9, 9},
        {0, 0, 0, 0, 13, 17, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0},
        {0, 0, 0, 17, 17, 17, 17, 17, 17, 17, 17, 17, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

    };
    for (int i = 0; i < rows; i++)
    {
        // cout << "Second Eaaxo\n"
            //  << i;
        for (int j = 0; j < columns; j++)
        {
            // cout << "Second Eddxo\n";
            cout << "Element at x[" << i
                 << "][" << j << "]: " << x[i][j];
            //    serach Diag
            bool hasDiag = true;
            int dept = 1;
            while (hasDiag)
            {
                cout << "while has diag \n";
                hasDiag = false;
                if (j - dept >= 0 && j + dept <= columns)
                {
                    if (i + dept <= rows)
                    {

                        if (x[i][j] == x[i + dept][j - dept] && x[i][j] == x[i + dept][j + dept])
                        {
                            dept++;
                            cout << "IL YA DIAG \n";
                            // continue;
                        }
                        // else if (x[i][j] != x[i + dept][j - dept] && x[i][j] != x[i + dept][j + dept]) //else
                         /*we removed else if , instead we used if only*/if (dept > 2)
                        {
                            //On a vraiment un dept de traingle
                            //        if(j-dept>=0 && j+dept<=columns){
                            //   if(i+dept<=rows){
                            //   }}
                            // has the same Base ?
                            cout << "LET SEE IF IT's Base \n";
                            int hasTheSameBase = 1;
                            for (int l = j - dept - 1; l < j + dept; l++)
                            {
                                if (x[i][j] == x[i + dept - 1][l])
                                {
                                    continue;
                                }
                                else
                                {
                                    hasTheSameBase = 0;
                                    break;
                                }
                            }
                            if (hasTheSameBase == 1)
                            {
                                cout << "the top of Triangle the has the same bas " << x[i][j] << " i " << i << " j " << j;
                                hasDiag = false;
                            }
                        }
                    }
                    else
                    {
                        hasDiag = false;
                    }
                }
                else
                {
                    hasDiag = false;
                }
            }

            // if(j-1>0 && j+1<columns){
            //     if(i+1<rows){
            //         if(x[i][j] == x[i+1][j-1] && x[i][j] == x[i+1][j+1]){
            //             cout << "On est sur le diag";
            //              if(j-2>0 && j+2<columns){
            //                   if(i+2<rows){
            //                     if(x[i][j] == x[i+2][j-2] && x[i][j] == x[i+2][j+2]){

            //                     }
            //                   }
            //              }
            //         }
            //     }
            // }
            // if(j-1>0 && j+1<columns){
            //     if(i+1<rows){
            //         if(x[i][j] == x[i+1][j-1] && x[i][j] == x[i+1][j+1]){
            //             cout << "On est sur le diag"
            //              if(j-2>0 && j+2<columns){
            //                   if(i+2<rows){
            //                     if(x[i][j] == x[i+2][j-2] && x[i][j] == x[i+2][j+2]){
            //  cout << "On est sur le diag Level 2";
            //                     }
            //                   }
            //              }
            //         }
            //     }
            // }
        }
    }
}
int main()
{
    // FirstExo();
    SecondExo();
    return 0;
}
