// commands to compile and run
// $ g++ array.cpp -o array
// $ ./array

#include <iostream>

using namespace std;

// static approach
void SecondExoStatic()
{
    cout << "Second Exo\n";
    // they want 10 rows 15 colums
    int rows = 10, columns = 15;
    int x[rows][columns] = {
        {1,2,3,4,5,    1,2,3,4,5,     1,2,3,4,5},
        {6,7,8,9,10,    1,2,3,4,5,     1,2,3,4,5},
        {11,12,13,14,15,    1,2,3,4,5,     1,2,3,4,5},
        {16,13,18,13,20,    1,2,3,4,5,     1,2,3,4,5},
        {13,13,13,13,13,    1,2,3,4,5,     1,2,3,4,5},
        {1,2,3,4,5,    1,2,3,4,5,     1,2,3,4,5},
        {18,18,18,18,18,     1,2,3,4,5,     1,2,3,4,5},
        {11,18,13,18,15,    1,2,3,4,5,     1,2,3,4,5},
        {16,13,18,13,20,    1,2,3,4,5,     1,2,3,4,5},
        {13,13,13,13,13,    1,2,3,4,5,     1,2,3,4,5}
    };
    int invertedX[rows][columns] ={};
     // Fill In invertesX and print X
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout << "X[" << i << "][" << j << "]="<<x[i][j]<<"\t";
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
                                    cout << "-- standing ---the top =" << x[i][j] << " i=" << i << " j=" << j <<" dept = " << dept+1<<"\n";
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
                                    cout << "-- inverted ---the top =" << invertedX[i][j] << " i " << rows-i-1 << " j " << j <<" dept = " << dept+1<<"\n";
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

// dynamic approach
void SecondExoDynamic()
{
    cout << "Second Exo\n";
    // they want 10 rows 15 colums
    int rows = 10, columns = 15;
    int x[rows][columns] = {};
    int invertedX[rows][columns] ={};
    // Scan user input array elements
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            //  dynamic approach
            cout << "Enter Element at x[" << i << "][" << j << "]: ";
            cin >> x[i][j];
        }
        cout<<endl;
    }
     // Fill In invertesX and print X
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout << "X[" << i << "][" << j << "]="<<x[i][j]<<"\t";
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
                                    cout << "-- standing ---the top =" << x[i][j] << " i " << i << " j " << j <<" dept = " << dept+1<<"\n";
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
                                    cout << "-- inverted ---the top =" << invertedX[i][j] << " i=" << rows-i-1 << " j=" << j <<" dept = " << dept+1<<"\n";
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
    int userInput;
    do {
        cout << "\n\n";
        cout << "for static approach entrer \t 1 \n for dynmamic approach enter \t 2 \n for EXIT enter \t 0 " << endl;
        cin >> userInput;
        cout << "\n\n";
        if(userInput==1){
            SecondExoStatic();
        }
        else if (userInput == 2){
            SecondExoDynamic();
        }
}
while (userInput != 0);
 cout << "EXIT ...\n";
}

// dynamic approach
void SecondExoDynamic()
{
    // they want 10 rows 15 colums
    int rows = 10, columns = 15;
    int x[rows][columns] = {};
    int invertedX[rows][columns] ={};
    // Scan user input array elements
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            //  dynamic approach
            cout << "Enter x[" << i << "][" << j << "] = ";
            cin >> x[i][j];
        }
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
                                    cout << "-- standing ---the top =" << x[i][j] << " i " << i << " j " << j <<" dept = " << dept+1<<"\n";
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
                                    cout << "-- inverted ---the top =" << invertedX[i][j] << " i=" << rows-i-1 << " j=" << j <<" dept = " << dept+1<<"\n";
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