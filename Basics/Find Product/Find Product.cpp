#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main() {
	int size = 0;
	cin >> size;
	
	int array[size];
	for (int counter = 0; counter < size; counter++) {
		cin >> array[counter];
	}
	
	long long answer = 1;
	for (int counter = 0; counter < size; counter++) {
		answer = ((answer * array[counter]) % ((int)pow(10, 9) + 7));
	}
	
	cout << answer << endl;
	
	return 0;
}
