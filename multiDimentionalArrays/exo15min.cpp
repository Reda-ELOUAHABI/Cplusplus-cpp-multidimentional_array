// g++ exo15min.cpp -o array
// ./array
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
    // INPUT
    int N = 15;
    char Letters[N] = {'a','w','e','r','f','d','c','i','g','u','k','o','r','e','s'};
    int NumberOfVowel =0;
    for (int i = 0; i < N; i++){
if(Letters[i] == 'a' || Letters[i] == 'e' 
|| Letters[i] == 'i' || Letters[i] == 'o' || Letters[i] == 'u' ){
    cout  << Letters[i] << " ";
    ++NumberOfVowel;
}
    }
    cout << endl << "The number of vowels = " << NumberOfVowel << endl;
    for (int i = 0; i < N; i++){
        cout << Letters[i] << " ";
    }
    cout << endl;
        
    return 0;
}