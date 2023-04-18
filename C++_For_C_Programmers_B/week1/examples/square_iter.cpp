/*
   This is an example shown by Dr. Iral Pohl.
*/

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
using namespace std;

template <typename ForwardIterator>

void square(ForwardIterator first, ForwardIterator last)
{
	for(; first!=last; first++)
		*first = (*first)*(*first);
}


int main()
{   
	vector<int> w; // a changable vector without elements

    for (int n = 0; n<5; ++n)
        w.push_back(n);  // use push_back to add an element in vector

	square(w.begin(), w.end());
	for (auto i: w)
		cout << i << "\t";
	cout << endl;

}