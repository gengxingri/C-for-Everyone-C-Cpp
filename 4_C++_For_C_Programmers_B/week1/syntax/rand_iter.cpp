/*
   This is an example shown bby Dr. Iral Pohl.

   Random Access Iterator
*/

#include <iostream>
#include <iterator>
#include <fstream>
#include <cstddef>
using namespace std;

template <typename RandomAccess> 
RandomAccess pickRandomEI(RandomAccess first, RandomAccess  last)
{
	ptrdiff_t temp = last - first; // result of pointer subtraction
	return first + rand()%temp;
}


int main()
{
   

	//cout << *pickRandEI(w.begin(), w.end())<< endl; // use
	
  
}