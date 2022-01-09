#include <iostream>
#include <cstdlib>


// ---- using ----
using namespace std;
using std::cin;
using std::cout;
using std::endl;
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
    cout<<" if the array is symmetric "<<endl;
    y = issymetric(arr, 0, n-1);
    cout<<y<<endl;

    cout<<"-----------------------------------"<<endl;
    // 10 - consecutive  sub array

    cout<<"-----------------------------------"<<endl;
    // 11 -

    cout<<"-----------------------------------"<<endl;

    // 12 -

    cout<<"-----------------------------------"<<endl;

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






















