// commands to compile and run
// $ g++ array.cpp -o array
// $ ./array

#include <iostream>

using namespace std;

// dynamic approach
void Exo3Dynamic()
{
    //  5 rows 17 columns
    int rows = 5, columns = 17;
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
            cout <<"  set_of_rules[ " << i << "] = ";
            cin >> set_of_rules[i];
        cout<<endl;
    }
    int *a = find_patterns(x,set_of_rules);
  cout << a[0] << endl;
}
int* find_patterns(int two_D_array[5][17], int one_D_array[6] ){
    int array_return={0,-1}
    return array_return;


}
int main()
{
SecondExoDynamic();
}
