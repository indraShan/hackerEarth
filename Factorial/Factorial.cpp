#include <iostream>
#include <climits>

using std::cout;
using std::cin;
using std::endl;

int multiply(int *array, int size, int number);
int factorial(int number);
void printArray(int *array, int size);

int main() {
	
	int number;
	cin >> number;
		
	// int array[500];
	//
	// int remainder = 0;
	// int quotient = number;
	// int index = 0;
	// while(quotient != 0) {
	// 	remainder = quotient%10;
	// 	quotient = quotient/10;
	// 	array[index] = remainder;
	// 	index++;
	// }
	//
	// int size = index+1;
	// for (int counter = number - 1; counter >=1; counter--) {
	// 	size = multiply(array, size, counter);
	// }
	//
	// for (int i = size - 1; i >= 0; i--) {
	// 	cout << array[i];
	// }
	//
	// cout << "" << endl;
	
	cout << factorial(number) << endl;
	
	return 0;
}

int factorial(int number) {
	if (number == 1) {
		return 1;
	}
	
	return number * factorial(number - 1);
}

int multiply(int *array, int size, int number) {
	int carry = 0;
	int counter = 0;
	while (counter < size) {
		int multi = array[counter];
		array[counter] = carry + ((multi * number) % 10);
		carry = ((multi * number) / 10);
		counter++;
	}
	
	while(carry != 0) {
		array[counter] = carry % 10;
		carry = carry/10;
		counter++;
	}
	
	return counter;
}