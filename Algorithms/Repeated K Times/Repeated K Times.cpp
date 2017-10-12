#include <iostream>
#include <map>
#include <climits>

int main() {
	int cases = 0;
	
	std::cin >> cases;
	
	int numbers[cases];
	for (int counter = 0; counter < cases; counter++) {
		std::cin >> numbers[counter];
	}
	
	int repeated = 0;
	std::cin >> repeated;
	
	// Key == the number
	// Value repeat count.
	std::map<int, int> repeatationLookUp;
	
	// This is the number that has repeated the required number of times.
	// Always stores the smallest number of the set that are found to repeat the required number of times.
	int matchKey = -1;
	// int rejectedKeys[]
	
	for (int counter = 0; counter < cases; counter++) {
		int key = numbers[counter];
		int repeatCount = repeatationLookUp.count(key) > 0?  repeatationLookUp.at(key) : 0;
		repeatationLookUp[key] = repeatCount + 1;
		
		// // 4 - rejected
		// // 3 - rejected
		// // 2 - stored, found again. Pop
		// if (repeatCount + 1 == repeated) {
		// 	// We have found a number that repeats at least as many times as required.
		// 	if (matchKey == -1) {
		// 		matchKey = key;
		// 	}
		// 	else if (key < matchKey) {
		// 		matchKey = key;
		// 		// We might need the key we are rejecting now (because the current number repeated more number of times than required)
		//
		// 	}
		// }
		// else if (repeatCount + 1 > repeated) {
		// 	repeatationLookUp.erase(key);
		// }
	}
	
	int smallest = INT_MAX;
	for (int counter = 0; counter < cases; counter++) {
		if (repeatationLookUp.at(numbers[counter]) == repeated) {
			if (numbers[counter] < smallest) {
				smallest = numbers[counter];
			}
		}
	}
	
	std::cout << smallest << std::endl;
	
	return 0; 
}