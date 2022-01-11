#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <cmath>

// ---- using ----
using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::exit;
using std::abs;


//---------------- prototypes ----------------------
void enter_array(int arr[], int n);
void init_array(int arr[], int n);
void print_array1(int arr[], int start, int end);
int binarySearch(int arr[], int l, int r, int searched_value);
void print_reverse1(int arr[], int start, int end);
int issymetric(int arr[], int begin, int end);
void presente_array(int arr[], int n);
int bubbleSort(int arr[], int begin, int end);
int  is_arithmetic_sequence(int array[], int start, int end, int d);
int sum_two_limb_is_third(int array[], int start, int end);
int is_symetricTest(int array[], int start, int end);
int count_subsets(int array[], int start, int end,int count,int assending, int descending);
int max_subsets(int array[], int start, int end,int max);
bool is_prime(int num,int i=2);
int initial_values(int array[], int start, int end);


//---------------- main ----------------------
    int n=10;
    int arr[10];
    int searched_value;
    bool sorted=false;

    int userInput;

int main(){
    cin >> userInput;
        switch(userInput) {
    case 1  :
    {
        // 1. Entering values for the array (the user will enter ten data).
        init_array(arr, n);
        enter_array(arr, n);
        main();
    }
    case 2  :
    {
            // 2. Schematic of all members of the array and presentation of the result.
            // -2 -33 12 88 12 -2 -1 1 9 1
            presente_array(arr, n);
			cout << endl;
            main();
    }
    case 3  :
    {
            // 3. Sort the array using the bubble sorting algorithm. 
            if(bubbleSort(arr,0, n)==1){
                    sorted = true;
                    // cout << "sorted";
            }
            // else{
            //     cout << "Not sorted";
            // }
            main();
    }
    case 4  :
    {
            // 4. Binary search of a desired value in an array. The user will enter the value,
            //  the output will be 1 if the value is in the array, and 0 if not.
            if(sorted == true){
                cin>>searched_value;
                int result = binarySearch(arr, 0, n - 1, searched_value);
                (result == 0)
                    ? cout <<"0"<<endl
                    : cout <<"1"<<endl;
            }else{
                cout<<"Error \n";
            }
            main();
    }
    case 5  :
    {
         // Checking whether the array members constitute an invoice series. 
            // == (Arithmetic sequence ==arithmetic progression)
            // The output will be 1 if yes, and 0 if not.
            // int array5[] ={1,2,3,4,5,6,7,8,9,10} ;
            int difference=arr[0]-arr[1];
            cout <<is_arithmetic_sequence(arr,1,n-1,difference)  << endl;
            main();
    }
    case 6  :
    {
        // Displays the contents of the array (from beginning to end).
            print_array1(arr, 0,n-1);
            cout<<endl;
            main();
    }
    case 7  :
    {
        // 7. Displays the contents of the array from end to beginning 
            print_reverse1(arr, 0,n-1);
            cout<<endl;
            main();
    }
    case 8  :
    {
        // Examine whether each of the arrays (starting from the third limb(==member)) is the sum of the two limbs that precede it.
            //  The output will be 1 if yes, and 0 if not.
            // int array8[] ={1,1,2,3,5,8,13,2,34,55} ; 4Tests
            cout << sum_two_limb_is_third(arr,2,n-1) << endl;
            main();
    }
    case 9  :
    {
        // 9 - symmetric/plinth array
            cout << is_symetricTest(arr,0,n-1) << endl;
            main();
    }
    case 10  :
    {
        // 10 - consecutive  sub array
            int count_subsetsint = 1; //by default , we will suppose there is already 1 subset with an order DESC or ASC
            cout << count_subsets(arr,0,n-1,count_subsetsint,0,0) <<endl;
            main();
    }
    case 11  :
    {
        // 11 - max of a given subsets
            int start11, end11;
            cin >> start11;
            cin >> end11;
            // check validity of user inputs
            if(start11 < 0 || end11 > n-1 || start11 > end11){
                start11 = 0 ;
                end11 = n-1;
            }
            cout << max_subsets(arr, start11, end11, arr[start11]) <<endl;
            main();
    }
    case 12  :
    {
        // 12 - initial numbers
        cout <<(initial_values(arr, 0,n-1) ? " " : " ") <<" " ;
        cout << endl;
        main();
    }
    case 13  :
    {
        exit(0);
    }
// executed every switch automaticly (by default)
    default :
        main();
    }
    return 0;
}

//---------------- functions ----------------------

void enter_array(int arr[], int n){
    static int i;
    int input;
    if(i==n){
        i = 0;
        return;
    }
    cin>>input;
    arr[i] = input;
    i++;
    enter_array(arr, n);

}


void init_array(int arr[], int n){
    static int i;
    if(i==n){
        i = 0;
        return;
    }
    arr[i] = 0;
    i++;
    init_array(arr, n);
}

void presente_array(int arr[], int n){
    static int i;
    if(i==n){
        i = 0;
        return;
    }
    cout<<"arr[" <<i<<"] "<<arr[i]<<" ";
    i++;
    presente_array(arr, n);
}

void print_array1(int arr[], int start, int end){
    if(start<=end){
        cout<<arr[start]<<" ";
        print_array1(arr, start+1,end);
    }
    
}


void print_reverse1(int arr[], int start, int end){
    // cout<<endl<< "start =" << start << " end= "<< end<<endl;
    if(start<=end){
        cout<<arr[end]<<" ";
        print_reverse1(arr, start,end-1);
    }
    
}
int bubbleSort(int arr[], int start, int end){
    if(start < end && end > 0){
        if(arr[start] > arr[start+1] && arr[start] !=0 && arr[start+1] !=0){
            int temp = arr[start];
            arr[start] = arr[start+1];
            arr[start+1] = temp;
        }
        bubbleSort(arr, start+1, end);
        bubbleSort(arr, start, end-1);
    }
    else
        return 1;
    return 1;
}

int binarySearch(int arr[], int l, int r, int searched_value){
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == searched_value)
            return mid;
        if (arr[mid] > searched_value)
            return binarySearch(arr, l, mid - 1, searched_value);
        return binarySearch(arr, mid + 1, r, searched_value);
    }

    return 0;
}

int issymetric(int arr[], int begin, int end){
    // base case
    if (begin >= end) {
        return 1;
    }
    if (arr[begin] == arr[end]) {
        return issymetric(arr, begin + 1, end - 1);
    }
    else {
        return 0;
    }
}

int  is_arithmetic_sequence(int array[], int start, int end, int d){ //should start with start==1 , to have a previous elt
	if(start > end) return 1; //we are at the end
	else if(array[start-1] - array[start] == d ){//the condition is true
			return  is_arithmetic_sequence(array,start+1,end,d);
    }
    //otherwise , we dont have exact difference d :
	return 0;
}
int sum_two_limb_is_third(int array[], int start, int end) //start == start from index 2 , not 0
{
	if(start > end) return 1; //we are at the end
	else if(array[start] == array[start-1] + array[start-2] ){//the condition is true
			return  sum_two_limb_is_third(array,start+1,end);
    }
    //otherwise , limbs do not verify the condition
	return 0;
}

int is_symetricTest(int array[], int start, int end)
{
	if(end <= 1) return 1;
    // check if the start and the end element are equal
	if (array[start] == array[end]) {
        // copy the remaining array (leaving start and end element)
        return is_symetricTest(array, start + 1, end - 1);
    }
		return 0;
}


int count_subsets(int array[], int start, int end,int count,int assending, int descending)
{
	// if(just_changed), bool just_changed
	if(start == end) return count;
	else  {
		if(array[start] > array[start+1] ){ //&& array[start]> array[start+2] 
			if(assending==1)  {
                ++count; 

                return  count_subsets(array,start+1,end,count,0,0);
                }
			// if(array[start+1]< array[start+2]) ++start;
			// we are in descending , let move to the next element
			return  count_subsets(array,start+1,end,count,0,1);
		}
		else if(array[start] < array[start+1] ){//&& array[start]< array[start+2]
			if(descending==1)   {
                ++count; 

                return  count_subsets(array,start+1,end,count,0,0);
                }
			// if(array[start+1]> array[start+2]) ++start;
			// we are in assending , let move to the next element
            return count_subsets(array,start+1,end,count,1,0);
		}
		// we have equivalent elements , so we wont change somthg, just let move to the next element
        return count_subsets(array,start+1,end,count,assending,descending);
    }
		return 0;
}
int max_subsets(int array[], int start, int end,int max)
{
	if(start == end) return max;
	else  {
		// in case next element is bigger than max
		if(array[start+1] > max ){
			return  max_subsets(array,start+1,end,array[start+1]);
		}
        return max_subsets(array,start+1,end,max);
    }
		return 0;
}
bool is_prime(int n,int i)
{
    // Base cases
    if (abs (n) <= 2)
        return (n == 2 || n==-2) ? true : false;
    if (abs (n) % i == 0)
        return false;
    if (i * i > abs (n))
        return true;
    // Check for next divisor
    return is_prime(n, i + 1);
}

int initial_values(int array[], int start, int end)
{
	if(start > end) return 1;
	else  {
		if(is_prime(array[start]) ){
			cout <<array[start]<<" ";
			return  initial_values(array,start+1,end);
		}
        return initial_values(array,start+1,end);
    }
		return 0;
}