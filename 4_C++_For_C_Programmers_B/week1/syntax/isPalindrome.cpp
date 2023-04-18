/*
   This is an example shown bby Dr. Iral Pohl.

   Bidirectional Iterator
*/

//reverse()
//STL algorithm using the bidirectional iterator

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
using namespace std;

template <typename Bidirectional> 
bool isPalindrome(Bidirectional first, Bidirectional last)
{
	while (true){
		last--;
		if (first == last) // assume >= undefined
			break;
		if (*first!=*last)
			return false;
		first++;
		if (first == last) 
			break;
	}
	return true;
}


int main()
{
	

}