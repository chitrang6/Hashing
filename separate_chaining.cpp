// THis is file demonestrates the hasing application.
// It also includes the hasing collision avoidance technique called Seprate Chaining.


#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <random>
#include <algorithm>

using namespace std;



// Let's define the size of the hase table which will have the store the value for the given key.
// Here we will implement two methods.

// 1. To store the name(string) of the citizens.

/*.   
	  Names
	 1.
	 2.
	 3.
	 4.
	 5.
	 6.
	 7.
	 8.
	 9.

*/


#define HASH_SIZE 25
vector <string> hash_table[HASH_SIZE];
#define  PRIME_NUMBER 11



/*

Store the data entries in the hash table. 
It will insert the data according to the key or index returned by the hash function

*/



void  store_data(string ); 




/*

This funtion implements the hashing function logic. THis will return the key computed by the hashing algorithm

THe hashing algorithm or function should be such that the distribution of the keys should be uniform and should not
clusttered to avoid the hashing collision.

*/


int hash_function(string ) ;


/*


This search function will tell whether the name is present in the list or not 
by retrieving the entry back using the hash function

*/


void search_data(string );


int hash_function(string S)
{


	int intermediateVal = 0;
	int i = 1;
	for(string :: iterator it = S.begin(); it != S.end(); ++it)
	{
    	intermediateVal = ((*it) * (i));
    	i++;
	}

	int key = intermediateVal % PRIME_NUMBER;
	cout<<"Hash key is:" << key << "  For String: " << S << endl;
	return key;
}






void store_data(string S)
{

	// Compute the key for the givenn string using thr hash function.

	int key = hash_function(S);
	hash_table[key].push_back(S);

}



void search_data(string S)
{
	int index = hash_function(S);

	// Now based on this index we will search either the string is present in that
	// linked list at that index or not


	for(int i = 0 ; i < hash_table[index].size() ; i++)
	{
		if(hash_table[index][i] == S)
		{
			cout<< "Found item: " << S << endl;
			return;
		}
	}

	cout<< "Not found !!!!  item: " << S << endl;
	
}




/*



Random string generator in C++




*/



int main()
{

	store_data("rwefsf");
	store_data("eafsvs");
	store_data("dawfsdf");
	store_data("dadafdafa");
	store_data("asdad");
	store_data("jjhfdf");
	store_data("yjdgfsgs");
	store_data("thgfasfgs");
	store_data("hjgfdscvbrt");
	store_data("jhytradsf");
	store_data("hywacvbhrew");


	search_data("jjhfdf");
	search_data("dasfas");

	return 0;
}







