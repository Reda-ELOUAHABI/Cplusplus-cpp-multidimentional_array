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
    // Custom Print
    //  for(int i=0;i<=rows;i++)
    // {
    //     for(int j=0;j<=columns;j++)
    //     {
    //         cout<<x[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    for (int i = 0; i <= rows; i++)
    {
        for (int j = 0; j <= columns; j++)
        {
            int dept = 0;
            while (dept < 11 && x[i][j] != 0)
            {
                ++dept;
                if (j - dept >= 0 && j + dept <= columns)
                {
                    if (i + dept <= rows)
                    {
                        if ((x[i][j] == x[i + dept][j - dept] || x[i][j] == x[i + dept][j + dept] && dept > 0) && (x[i][j] == x[i + dept][j - dept] || x[i][j] == x[i + dept][j + dept] && dept == 0)) //faute , dept start already with 1 : ++dept
                        {
                            // cout << "[" << i << " : " << j << " ] \t DIAG de x[i][j] :" << x[i][j] << " = G: " << x[i + dept][j - dept] << " && D:  " << x[i][j] << " = " << x[i + dept][j + dept] << " Dept = " << dept << endl;
                            if (dept >= 2)
                            {
                                // cout << " dept BIGGER than 2 and it == " << dept << endl;
                                bool isTRG = false;
                                for (int p = j - dept + 1; p < j - dept + 3; p++)
                                {
                                    cout << "Elements of base = " << x[i][p] << " i = "<< i << " p = "<< p << " j = "<< j << " dept = "<< dept << " x[i][j] "<<x[i][j]<< endl;
                                    // cout << p << i << x[i][j] << endl;
                                    // if (x[i][p] == x[i][j])
                                    // {
                                    //     isTRG = true;
                                    // }
                                    // else
                                    // {
                                    //     isTRG = false;
                                    //     break;
                                    // }
                                }
                                if (isTRG)
                                {
                                    cout << "-----the top of Triangle the has the same bas " << x[i][j] << " i " << i << " j " << j << "\n";
                                    break;
                                }
                            }

                            dept++;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
}





































void SecondTest()
{
    cout << "Second Exo\n";
    int rows = 10, columns = 5;
    int x[rows][columns] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,13,18,13,20},
        {13,13,13,13,13},
            {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,13,18,13,20},
        {13,13,13,13,13}
    };

     // Custom Print
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout << "[" << i << "][" << j << "]="<<x[i][j]<<"\t";
            // cout << "x[" << i << "][" << j << "]: "<<x[i][j] <<endl;
        }
        cout<<endl;
    }

     for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            // cout<<x[i][j]<<"\t";
            // cout << "x[" << i << "][" << j << "]: "<<x[i][j] <<endl;
            int dept=1;
            while(dept<rows){
                // we are not at extremities
                if ((j - dept >= 0 && j + dept <= columns) && i + dept <= rows){
                    // see if element in diag has the same value                  
                    if (x[i][j]== x[i+dept][j-dept] ||  x[i][j] == x[i + dept][j + dept])
                        {
                            cout << "[" << i << " : " << j << " ] :" << x[i][j] << " = G: " << x[i + dept][j - dept] << " && D:  " << x[i + dept][j + dept] << " Dept = " << dept << endl;
                            if (dept >= 2){
                                bool sameBase = false;
                                // the rol how node od triangle disperse [dept=0,disp=0], [1,3],[2,5] ..
                                // so we calsulate the distance = j+dept - (j-dept) +1
                                for (int p = 0; p < (2 *dept)+ 1; p++)
                                {
                                    // cout << x[i+dept][j-dept] << endl;
                                    if(x[i][j] ==  x[i+dept][j-dept]){
                                        sameBase=true;
                                    }
                                    else{
                                        sameBase=false;
                                    }
                                }
                                if (sameBase)
                                {
                                    cout << "-----the top =" << x[i][j] << " i " << i << " j " << j <<" dept = " << dept+1<<"\n";
                                    break;
                                }
                            }
                        }
                        else{ break;}
                }
                else{ break;}
                ++dept;
            }
        }
        // cout<<endl;
    }
}

int main()
{
    // FirstExo();
    SecondTest();
    return 0;
}

