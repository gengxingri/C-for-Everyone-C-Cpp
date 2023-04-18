//Introduction to C++

//Miles are converted to kiloeters

#include <iostream>
using namespace :: std;

const double m_to_k = 1.609;

// inline is not widely used thanks to compiler flag "optimize", but this one
// is here for educational purposes
inline double convert(int mi){
	return (mi * m_to_k);
}

int main(void)
{
	int miles = 1;
	while (miles != 0){
		cout << "Input distance in miles or 0 to determinate:";
		cin  >> miles;
		cout <<"\n Distance is " << convert(miles) << " km." << endl;
	}
	cout << endl;
}