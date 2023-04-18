/* 
  Simple STL vector program

  Use with a file
*/

#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <numeric>

using namespace std;


int main()
{
	ifstream myin("data");

	istream_iterator<int> in(myin);

	istream_iterator<int> eos;

  cout << "Sum of the data is "
		   << accumulate(in, eos, 0)
		   << endl;
		   
  // An example
	int data[4] = {1,2,3,4};

  cout << accumulate(data, data + 4, 5);
   
	return 0;
}
