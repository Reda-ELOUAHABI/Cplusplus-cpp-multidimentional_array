
#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <iterator>

//---------------- using -------------------------
using std::cin;
using std::cout;
using std::endl;
using std::setw;
//---------------- consts ------------------------

const int N9 = 5;
const int N10 = 10;
//---------------- prototypes --------------------

// int is_symetric( const int arr[]);
// int getLastElement(const int array[]);

//---------------- main ----------------------
int is_symetricTest(int array[], int start, int end)
{
	// cout << "start" << start << " : "<<array[start] <<" &&  end"<< end << " : " <<array[end]<<endl;
	if(end <= 1) return 1;
    // check if the first and the last element are equal
	if (array[start] == array[end]) {
		// cout << "COCOCOC" ;
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
bool is_prime(int num) {
    for (int i = num - 1; i > 1; i--) {
        if ((num % i) == 0)
            return false;
    }
    return true;
}

int initial_values(int array[], int start, int end)//int array1[],int &size
{
	// cout << "start" << start << " : "<<array[start] <<" &&  end "<< end << " : " <<array[end] << " max : "<< max <<endl;
		// size = end - start;
	    // int *Array = new int[size];
	    // for (int i = 0; i < size; ++i)
	    //     std::cin >> Array[i];

	//     return Array;
	// 	int main() {
	//     int size;
	//     int *arr = array_(size);
	//     // ...
	//     delete[] arr; // Don't forget to delete[] what has been new[]'d!
	// }
	if(start == end) return 1;
	else  {
		// in case next element is bigger than max
		if(is_prime(array[start]) ){
			// ++size;
			// array1[size] = array[start];
			cout << "\n initial number in the array = " <<array[start];
			return  initial_values(array,start+1,end);//array1,size
		}
        return initial_values(array,start+1,end);//array1,size
    }
		return 0;
}





int main()
{
	// 9
	// 
	int array9[] = { 1, 2, 3, 2, 1};
	cout <<"array is  symetric ? : \t" <<( is_symetricTest(array9,0,N9-1) ? "Yes" : "NO" ) << endl;
	// 10
	// 
	// int array10[] ={9,8,6,4,1,3,6,6,7,9}; //should give 2
	int array10[] ={9,8,6,4,1,3,6,4,5,9} ; //should give 3
	// bool just_changed= false;,just_changed
	int count_subsetsint =1; //by default , we will suppose there is already 1 subset with an order DESC or ASC
	cout <<"array is  constitued by  : "<< count_subsets(array10,0,N10-1,count_subsetsint,0,0) << " subsets" <<endl;
	// 11
	// 
	int start11, end11;
	cout << "enter the start position : \n" << endl;
	cin >> start11;
	cout << "enter the end position : \n" << endl;
	cin >> end11;
	// check validity of user inputs
	if(start11 < 0 || end11 > N10-1 || start11 > end11){
		start11 = 0 ;
		end11 = N10-1;
		cout << "USER INPUT WAS INVALID" << endl;
	}
	cout <<"Max array is    : "<< max_subsets(array10, start11, end11, array10[start11]) <<endl;
	// 12
	// 
	cout <<"initial numbers in array are    : "<< initial_values(array10, 0,N10-1) <<endl;
	


}

// int is_symetric(const int array[*(&array + 1) - array])
// {
// 	cout << "sizeof(array)\t"<< *(&array + 1) - array <<endl;
// 	if(*(&array + 1) - array <= 1) return 1;
// 	// if(sizeof(array)/sizeof(array[0]) <= 1) return 1;

//     // check if the first and the last element are equal
//     // if(getLastElement(array) == array[sizeof(array)/sizeof(array[0]) -1])
// 	else{
// 	 // copy the remaining array (leaving first and last element)
// 	 cout << "HII";
// 		int dest[*(&array + 1) - array -1]={};
// 		int x=*(&array + 1) - array-1;
// 		cout <<x;
// 		 for(int i = 0 ; i < x ; i++){cout << "HII";}
// 		for(int i =0;i<*(&array + 1) - array-1;i++){
			
// 			dest[i]=array[i+1];
// 			cout<<"dest["<<i<<"]"<<dest[i]<<endl;
// 		}

// 		// std::copy(std::start(array), std::end(array), std::start(dest));
//         // return is_symetric(dest);
//         return 1;
//         // return is_symetric(Arrays.copyOfRange(array, 1, sizeof(array)/sizeof(array[0])-1));
// 	}
       
//     return 0;
// 	// bool isSymetric=fals;
// 	// int max;
// 	// if (index == N-1)
// 	// 	return arr[index];

// 	// max = is_symetric( arr, index+1);
// 	// return (isSymetric ? 1 : 2);
// }
// int getLastElement(const int array[]) {
//     return array[0];    
// }
