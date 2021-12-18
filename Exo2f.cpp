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
    // 10 rows 15 colums
    int rows = 10, columns = 15;
    int matrix[rows][columns] = {};
    int invertedMatrix[rows][columns] ={};
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
     // Fill In invertedMatrix
     // we invert rows of normal matrix Upside down
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            invertedMatrix[rows-i-1][j]=matrix[i][j];
        }
    }
    // A : count triangles that has max triangle_size
    // B : Maximum triangle size [triangle_size]
    int A=0,B=0;
    // serach traingle on normal matrix
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            int triangle_size=1;//initialise the triangle size
            while(triangle_size<rows){
                // we are not at extremities
                if ((j - triangle_size >= 0 && j + triangle_size <= columns) && i + triangle_size <= rows && matrix[i][j]!=0){
                    // see if element in diag has the same value
                    if (matrix[i][j]== matrix[i+triangle_size][j-triangle_size] ||  matrix[i][j] == matrix[i + triangle_size][j + triangle_size])
                        {
                            if (triangle_size >= 2){
                                bool sameBase = false;//we suppose at first that the diagonal base has not the same values at row
                                // the role how node of triangle disperse [triangle_size=0,disp=0], [1,3],[2,5] ..
                                // so we calsulate the distance = j+triangle_size - (j-triangle_size) +1
                                for (int p = 0; p < (2 *triangle_size)+ 1; p++)
                                {
                                    if(matrix[i][j] ==  matrix[i+triangle_size][j-triangle_size]){
                                        sameBase=true; //we found same base
                                    }
                                    else{
                                        sameBase=false;
                                    }
                                }
                                if (sameBase)//we have a real triangle
                                {
                                    cout << i << " " <<  j <<": " << triangle_size+1 << " standing. Value: " << matrix[i][j] <<endl;
                                    if(B<triangle_size+1){//this is the first triangles that has max triangle_size
                                        B=triangle_size+1;//set the max size
                                        A=1;
                                    }
                                    else if(B==triangle_size+1){
                                        ++A;//increment counter of triangles that has max triangle_size
                                    }
                                    break;
                                }
                            }
                        }
                        else{ break;}
                }
                else{ break;}
                ++triangle_size;
            }
        }
    }
     // serach traingle on invertedMatrix [same logic as normal array 'matrix']
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            int triangle_size=1;
            while(triangle_size<rows){
                // we are not at extremities
                if ((j - triangle_size >= 0 && j + triangle_size <= columns) && i + triangle_size <= rows && invertedMatrix[i][j] !=0){
                    // see if element in diag has the same value
                    if (invertedMatrix[i][j]== invertedMatrix[i+triangle_size][j-triangle_size] ||  invertedMatrix[i][j] == invertedMatrix[i + triangle_size][j + triangle_size])
                        {
                            if (triangle_size >= 2){
                                bool sameBase = false;
                                for (int p = 0; p < (2 *triangle_size)+ 1; p++)
                                {
                                    if(invertedMatrix[i][j] ==  invertedMatrix[i+triangle_size][j-triangle_size]){
                                        sameBase=true;
                                    }
                                    else{
                                        sameBase=false;
                                    }
                                }
                                if (sameBase)
                                {
                                    cout << rows-i-1 << " " <<  j <<": " << triangle_size+1 << " inverted. Value: " << invertedMatrix[i][j] <<endl;
                                    if(B<triangle_size+1){
                                        B=triangle_size+1;
                                        A=1;
                                    }
                                    else if(B==triangle_size+1){
                                        ++A;
                                    }
                                    break;
                                }
                            }
                        }
                        else{ break;}
                }
                else{ break;}
                ++triangle_size;
            }
        }
    }
    cout << A << " " << B << endl;
    return EXIT_SUCCESS;
}
