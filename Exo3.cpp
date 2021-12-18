// commands to compile and run
// $ g++ array.cpp -o array
// $ ./array

#include <iostream>

using namespace std;

// dynamic approach
void Exo3Dynamic()
{
    //  5 rows 17 columns
    int rows = 6, columns = 18;
    //     int x[rows][columns] = {
    //     {1,2,3,4,5,    1,2,3,4,5,     1,2,3,4,5},
    //     {6,7,8,9,10,    1,2,3,4,5,     1,2,3,4,5},
    //     {11,12,13,14,15,    1,2,3,4,5,     1,2,3,4,5},
    //     {16,13,18,13,20,    1,2,3,4,5,     1,2,3,4,5},
    //     {13,13,13,13,13,    1,2,3,4,5,     1,2,3,4,5},
    //     {1,2,3,4,5,    1,2,3,4,5,     1,2,3,4,5},
    //     {18,18,18,18,18,     1,2,3,4,5,     1,2,3,4,5},
    //     {11,18,13,18,15,    1,2,3,4,5,     1,2,3,4,5},
    //     {16,13,18,13,20,    1,2,3,4,5,     1,2,3,4,5},
    //     {13,13,13,13,13,    1,2,3,4,5,     1,2,3,4,5}
    // };
    int x[rows][columns] = {};
    // set N to be 5
    ini N=6;
    int set_of_rules[N] = {};
    enum patterns_t
    {   EVEN_PT, POSITIVE_PT, DIVIDE_BY_3_MPT};

    // Scan user input array elements
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout << i << " * " << j << " = ";
            cin >> x[i][j];
        }
        cout<<endl;
    }
    // Scan user input into set_of_rules
    for(int i=0;i<N;i++)
    {
        /*
        zero will indicate that he is looking for EVEN_PT, 1 will indicate that he is looking for POSITIVE_PT, 2 will indicate that he is looking for DIVIDE_BY_3_MPT.
        Example of input to be fed into a set of rules (if we set N to be 6): 0 1 0 1 2
        */
            cout <<"  set_of_rules[ " << i << "] = ";
            cin >> set_of_rules[i];
        cout<<endl;
    }

     // Fill In invertesX and print X
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            // cout << "X[" << i << "][" << j << "]="<<x[i][j]<<"\t";
            invertedX[rows-i-1][j]=x[i][j];
        }
        cout<<endl;
    }
    // // Print the inverted
    // for(int i=0;i<rows;i++)
    // {
    //     for(int j=0;j<columns;j++)
    //     {
    //         // cout << "X[" << i << "][" << j << "]="<<x[i][j]<<"\t";
    //         cout << "invertedX[" << i << "][" << j << "]="<<invertedX[i][j]<<"\t";
    //         // cout << "x[" << i << "][" << j << "]: "<<x[i][j] <<endl;
    //     }
    //     cout<<endl;
    // }
    // A : count triangle that has max dept
    // B : mAx Dept
    int A=0,B=0;
    // serach traingle on x
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
                            // cout << "[" << i << " : " << j << " ] :" << x[i][j] << " = G: " << x[i + dept][j - dept] << " && D:  " << x[i + dept][j + dept] << " Dept = " << dept << endl;
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
                                    cout << i << " " <<  j <<": " << dept+1 << " standing. Value: " << x[i][j] <<endl;
                                    if(B<dept+1){
                                        B=dept+1;
                                        A=1;
                                    }
                                    else if(B==dept+1){
                                        ++A;
                                    }
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
     // serach traingle on invertedX [same logic as x]
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            int dept=1;
            while(dept<rows){
                // we are not at extremities
                if ((j - dept >= 0 && j + dept <= columns) && i + dept <= rows){
                    // see if element in diag has the same value
                    if (x[i][j]== invertedX[i+dept][j-dept] ||  invertedX[i][j] == invertedX[i + dept][j + dept])
                        {
                            // cout << "[" << i << " : " << j << " ] :" << invertedX[i][j] << " = G: " << invertedX[i + dept][j - dept] << " && D:  " << invertedX[i + dept][j + dept] << " Dept = " << dept << endl;
                            if (dept >= 2){
                                bool sameBase = false;
                                // the rol how node od triangle disperse [dept=0,disp=0], [1,3],[2,5] ..
                                // so we calsulate the distance = j+dept - (j-dept) +1
                                for (int p = 0; p < (2 *dept)+ 1; p++)
                                {
                                    // cout << invertedX[i+dept][j-dept] << endl;
                                    if(invertedX[i][j] ==  invertedX[i+dept][j-dept]){
                                        sameBase=true;
                                    }
                                    else{
                                        sameBase=false;
                                    }
                                }
                                if (sameBase)
                                {
                                    cout << rows-i-1 << " " <<  j <<": " << dept+1 << " standing. Value: " << invertedX[i][j] <<endl;
                                    if(B<dept+1){
                                        B=dept+1;
                                        A=1;
                                    }
                                    else if(B==dept+1){
                                        ++A;
                                    }
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
    cout << A << " " << B << endl;
}
int main()
{
SecondExoDynamic();
}
