#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <iterator>


// ---- using ----
using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::exit;
#define EXIT_SUCCESS


//---------------- prototypes ----------------------
void enter_array(int arr[], int n);
void copy_array(int arr[], int copy_arr[], int n);
void init_array(int arr[], int n);
void print_array(int arr[], int n);
bool bubbleSort(int arr[], int n);
int binarySearch(int arr[], int l, int r, int x);
void print_reverse(int arr[], int n);
int issymetric(int arr[], int begin, int end);
//
//
int is_symetricTest(int array[], int start, int end);
int count_subsets(int array[], int start, int end,int count,int assending, int descending);
int max_subsets(int array[], int start, int end,int max);
bool is_prime(int num);
int initial_values(int array[], int start, int end);



/*
    notes:
        fix the loop in  the bubble sort
        solve invoice series
*/

//---------------- main ----------------------

int main(){
    int n=10;
    int arr[n], sorted_arr[n];
    int x, y;
    bool sorted=false;
    init_array(arr, n);
    cout<<"-----------------------------------"<<endl;
    enter_array(arr, n);
    cout<<"-----------------------------------"<<endl;
    // 3 - bubble sort
    copy_array(arr, sorted_arr, n);
    // I commented this function bcs it gives an error
    sorted = bubbleSort(sorted_arr, n);
    cout<<"-----------------------------------"<<endl;
    // 4 - binary search
    cout<<"Enter value to search for: "<<endl;
    cin>>x;
    if(sorted == true){
        int result = binarySearch(sorted_arr, 0, n - 1, x);
        (result == -1)
            ? cout <<"0"
            : cout <<"1 "<<endl;
    }else{
        cout<<"message: Error \n";
    }
    // 5 -
    cout<<"-----------------------------------"<<endl;
    // 6 - show array
    cout<<"sorted array "<<endl;
    print_array(sorted_arr, n);

    cout<<"-----------------------------------"<<endl;
    // 7 - print in reverse
    cout<<"reversed array "<<endl;
    print_reverse(arr, n);

    cout<<"-----------------------------------"<<endl;
    // 8 -

    cout<<"-----------------------------------"<<endl;

    // 9 - symmetric
    // cout<<" if the array is symmetric "<<endl;
    // y = issymetric(arr, 0, n-1);
    // cout<<y<<endl;
	cout <<"array is  symetric ? : \t" <<( is_symetricTest(arr,0,n-1) ? "Yes" : "NO" ) << endl;

    cout<<"-----------------------------------"<<endl;
    // 10 - consecutive  sub array
	// int array10[] ={9,8,6,4,1,3,6,6,7,9}; //should give 2
	// int array10[] ={9,8,6,4,1,3,6,4,5,9} ; //should give 3
	int count_subsetsint =1; //by default , we will suppose there is already 1 subset with an order DESC or ASC
	cout <<"array is  constitued by  : "<< count_subsets(arr,0,n-1,count_subsetsint,0,0) << " subsets" <<endl;

    cout<<"-----------------------------------"<<endl;
    // 11 - max of a given subsets

	int start11, end11;
	cout << "enter the start position : \n" << endl;
	cin >> start11;
	cout << "enter the end position : \n" << endl;
	cin >> end11;
	// check validity of user inputs
	if(start11 < 0 || end11 > n-1 || start11 > end11){
		start11 = 0 ;
		end11 = n-1;
		cout << "USER INPUT WAS INVALID" << endl;
	}
	cout <<"Max array is    : "<< max_subsets(arr, start11, end11, arr[start11]) <<endl;

    cout<<"-----------------------------------"<<endl;

    // 12 - initial numbers
	// 
	cout <<"initial numbers in array are    : "<< initial_values(arr, 0,n-1) <<endl;

    cout<<"-----------------------------------"<<endl;


// 
// 
// 
// 


        int userInput;
    do {
        cout << "\n\n";
        cout << "for __1__ entrer : \t 1 \n
                for __2__ entrer :  \t 2 \n
                for __3__ entrer :  \t 3 \n
                for __4__ entrer :  \t 4 \n
                for __5__ entrer :  \t 5 \n
                for __6__ entrer :  \t 6 \n
                for __7__ entrer :  \t 7 \n
                for __8__ entrer :  \t 8 \n
                for __9__ entrer :  \t 9 \n
                for __10__ entrer :  \t 10 \n
                for __11__ entrer :  \t 11 \n
                for __12__ entrer :  \t 12 \n
                for EXIT enter \t 13 " << endl;
        cin >> userInput;
        cout << "\n\n";
        if(userInput==1){
        //    1;
        }
        else if (userInput == 2){
            // 2;
        }
        else if (userInput == 3){
            // 3;
        }
        else if (userInput == 4){
            // 4;
        }
        else if (userInput == 5){
            // 5;
        }
        else if (userInput == 6){
            // 6;
        }
        else if (userInput == 7){
            // 7;
        }
        else if (userInput == 8){
            // 8;
        }
        else if (userInput == 9){
            // 9;
        }
        else if (userInput == 10){
            // 10;
        }
        else if (userInput == 11){
            // 11;
        }
        else if (userInput == 12){
            // 12
        }
}
while (userInput != 13);
 cout << "EXIT ...\n";
    return 0;
}

void enter_array(int arr[], int n){
    static int i;
    int x;
    if(i==n){
        i = 0;
        cout<<endl;
        return EXIT_SUCCESS;;
    }
    cout<<"Enter Value "<<i+1<<endl;
    cin>>x;
    arr[i] = x;
    i++;
    enter_array(arr, n);

}

void copy_array(int arr[],int copy_arr[], int n){
    static int i;
    int x;
    if(i==n){
        i = 0;
        cout<<endl;
        return EXIT_SUCCESS;
    }
    copy_arr[i] = arr[i];
    i++;
    copy_array(arr, copy_arr, n);

}

void init_array(int arr[], int n){
    static int i;
    if(i==n){
        i = 0;
        cout<<endl;
        return EXIT_SUCCESS;
    }
    arr[i] = 0;
    i++;
    init_array(arr, n);
}

void print_array(int arr[], int n){
    static int i;
    if(i==n){
        i = 0;
        cout<<endl;
        return EXIT_SUCCESS;
    }
    cout<<arr[i]<<" ";
    i++;
    print_array(arr, n);

}

void print_reverse(int arr[], int n){
    static int i=n-1;
    if(i==0){
        cout<<arr[i]<<" "<<endl;
        return EXIT_SUCCESS;
    }
    cout<<arr[i]<<" ";
    i--;
    print_reverse(arr, n-1);
}

bool bubbleSort(int arr[], int n){
    cout << n<< "\t";
    bool sorted = false;
     // Base case
    if (n == 1)
        return -1;
    // One pass of bubble sort. After
    // this pass, the largest element
    // is moved (or bubbled) to end.
    for (int i=0; i<n-1; i++)
        if (arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    // Largest element is fixed,
    // recur for remaining array
    bubbleSort(arr, n-1);
    sorted = true;
}

int binarySearch(int arr[], int l, int r, int x){
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
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


// 
// 
int is_symetricTest(int array[], int start, int end)
{
	// cout << "start" << start << " : "<<array[start] <<" &&  end"<< end << " : " <<array[end]<<endl;
	if(end <= 1) return 1;
    // check if the first and the last element are equal
	if (array[start] == array[end]) {
        // copy the remaining array (leaving first and last element)
        return is_symetricTest(array, start + 1, end - 1);
    }
		return 0;
}


int count_subsets(int array[], int start, int end,int count,int assending, int descending)
{
	// if(just_changed), bool just_changed
	// cout << "start" << start << " : "<<array[start] <<" &&  suivant "<< start+1 << " : " <<array[start+1] << " count : "<< count << " ASC "<<assending<<" DESC "<<descending<<endl;
	if(start == end) return count;
	else  {
		if(array[start] > array[start+1] ){ //&& array[start]> array[start+2] 
			if(assending==1)  {++count; 
			//! we could here specify the two cases with if array[start+1]> array[start+2]  == DESC=1 et vis vers ca
			return  count_subsets(array,start+1,end,count,0,0);}
			// if(array[start+1]< array[start+2]) ++start;
			// we are in descending , let move to the next element
			return  count_subsets(array,start+1,end,count,0,1);
		}
		else if(array[start] < array[start+1] ){//&& array[start]< array[start+2]
			if(descending==1)   {++count; 
				//! we could here specify the two cases with if array[start+1]> array[start+2]  == DESC=1 et vis vers ca
			return  count_subsets(array,start+1,end,count,0,0);}
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
	// cout << "start" << start << " : "<<array[start] <<" &&  end "<< end << " : " <<array[end] << " max : "<< max <<endl;
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
bool is_prime(int num)
{
    for (int i = num - 1; i > 1; i--) {
        if ((num % i) == 0)
            return false;
    }
    return true;
}

int initial_values(int array[], int start, int end)
{
	if(start == end) return 1;
	else  {
		if(is_prime(array[start]) ){
			cout << "\n" <<array[start];
			return  initial_values(array,start+1,end);
		}
        return initial_values(array,start+1,end);
    }
		return 0;
}



















