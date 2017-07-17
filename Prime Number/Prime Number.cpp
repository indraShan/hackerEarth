#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;


int main() {
	
	int input;
	cin >> input;
	
	int primes[input+1];
	primes[0] = 0;
	primes[1] = 0;
	
	for (int counter = 2; counter <= input; counter++) {
		primes[counter] = counter;
	}
	
	for (int counter = 2; counter <= pow(input, 0.5); counter++) {
		for (int divisor = 2; divisor <= input; divisor++) {
			if (counter * divisor > input) {
				break;
			}
			else if (primes[counter * divisor] == 0) {
				continue;
			}
			primes[counter * divisor] = 0;
		}
	}
	
	for (int counter = 2; counter <= input; counter++) {
		if (primes[counter] != 0) {
			cout << primes[counter] << " ";
		}
	}
	
	
	cout << endl;
	
	
	
	return 0;
}