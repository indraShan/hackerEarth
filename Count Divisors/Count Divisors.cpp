#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main() {
	
	int l, r, k;
	
	cin >> l >>  r >> k;


	// O(n)
	// int divisors = 0;
	// for (int counter = l; counter <= r; counter++) {
	// 	if (counter % k == 0) {
	// 		divisors++;
	// 	}
	// }
	//
	// cout << divisors << endl;
	
	
	//O(1)
	cout << (r/k) - ((l-1)/k) << endl;
	
	return 0;
}