#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int nearestPrimeToNumber(int number);
void setupPrimes();

// ASCII table contains 127 chacaters.
int size = 123;
int primes[123];

int main() {
	
	setupPrimes();

	int cases;
	cin >> cases;
	
	
	for (int counter = 0; counter < cases; counter++) {
		int length;
		cin >> length;
		
		cin.ignore();
		cin.clear();
		
		string input;
		getline(cin, input);
		// length = input.length();
		char word[length + 1];
		for (int index = 0; index < length; index++) {
			int number = input[index];
			// cout << "Numbers = " << number << endl;
			int prime = nearestPrimeToNumber(number);
			// cout << "Prime = " << (char)prime << endl;
			word[index] = prime;
		}
		word[length] = '\0';
		cout << word << endl;
	}
	
	return 0;
}

void setupPrimes() {
	for(int counter = 0; counter < size; counter++) {
		primes[counter] = 0;
		if (counter >= 91 && counter <= 96) {
			continue;
		}
		if (counter >= 65) {
			primes[counter] = counter;
		}
		
	}
	for(int counter = 2; counter <= pow(size, 0.5); counter++) {
		for (int divisor = 2; divisor * counter < size; divisor++) {
			primes[divisor * counter] = 0;
		}
	}
	
	
	// for(int counter = 0; counter < size; counter++) {
	// 	if (primes[counter] != 0) {
	// 		cout << primes[counter] << endl;
	// 	}
	// }
}

int nearestPrimeToNumber(int number) {
	int backDistance = 0;
	int backPrime = -1;
	for (int counter = number; counter >=2; counter--) {
		backDistance++;
		if (primes[counter] != 0) {
			backPrime = primes[counter];
			break;
		}
		
	}
	int forDistance = 0;
	int forPrime = -1;
	for (int counter = number; counter < size; counter++) {
		forDistance++;
		if (primes[counter] != 0) {
			forPrime = primes[counter];
			break;
		}	
	}

	// cout << "Number = " << number << " backprime = " << backPrime << " forPrime = " << forPrime << " backDistance = " << backDistance << " forDistance = " << forDistance << endl;
	if (backPrime == -1) {
		return forPrime;
	}
	if (forPrime == -1) {
		return backPrime;
	}
	if (backDistance == forDistance) {
		return (backPrime < forPrime) ? backPrime : forPrime;
	}
	return (backDistance < forDistance) ? backPrime : forPrime;
}
