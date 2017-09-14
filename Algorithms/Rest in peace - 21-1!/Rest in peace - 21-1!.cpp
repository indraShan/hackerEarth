#include <iostream> 
#include <string>
#include <cmath>

bool numberContainsDigit(int number, int digit);
int hash(const char *input, int start, int end, int inputSize, char previous, char next, int previousHash);

int main () {

	int cases = 0;
	std::cin >> cases;

	int numbers[cases];
	for (int counter = 0; counter < cases; counter++) {
		std::cin >> numbers[counter];
	}
	
	// Indrajit
	// char test[3] = {'a','j','i'};
	//
	// char pattern[3] = {'j', 'i', 't'};
	//
	// int key = hash(pattern, 3, '\0', '\0', 0);
	//
	// std::cout << "Pattern hash = " << key << std::endl;
	//
	// key = hash(test, 3, '\0', '\0', 0);
	//
	// std::cout << "aji hash = " << key << std::endl;
	//
	// char match[3] = {'j', 'i', 't'};
	//
	// key = hash(match, 3, 'a', 't', key);
	//
	// std::cout << "jit hash = " << key << std::endl;

	for (int counter = 0; counter < cases; counter++) {
		if (numbers[counter] % 21 == 0 || numberContainsDigit(numbers[counter], 21) == true) {
			std::cout << "The streak is broken!" << std::endl;
		}
		else {
			std::cout << "The streak lives still in our heart!" << std::endl;
		}
	}
	
	return 0;
}

// Brute force.
// bool numberContainsDigit(int number, int digit) {
// 	std::string string = std::to_string(number);
// 	std::string pattern = std::to_string(digit);
//
// 	const char*  stringArray = string.c_str();
// 	const char* patternArray = pattern.c_str();
//
// 	int stringLength = string.length();
// 	int patternLength = pattern.length();
//
// 	// Indrajit (5-7)
// 	// jit (0-2)
// 	for (int counter = 0; counter < stringLength; counter++) {
// 		for (int j = 0; j < patternLength; j++) {
// 			if (stringArray[counter + j] != patternArray[j]) {
// 				break;
// 			}
// 			if (j == patternLength - 1 && stringArray[counter + j] == patternArray[j]) {
// 				return true;
// 			}
// 		}
// 	}
//
// 	return false;
// }

int hash(const char *input, int start, int end, int inputSize, char previous, char next, int previousHash) {
	int hash = 0;
	if (previous == '\0' && next == '\0') {
		for (int counter = end-1; counter >= start; counter--) {
			hash += (input[counter] * (pow(101, (end-start-1) - counter)));
		}		
		return hash;
	}
	hash = previousHash;
	hash = (101 * (hash - (previous * pow(101, end-start - 1)))) + (next * 1);
	return hash;
}

// Rabin-karph
bool numberContainsDigit(int number, int digit) {
	std::string string = std::to_string(number);
	std::string pattern = std::to_string(digit);
	
	const char*  stringArray = string.c_str();
	const char* patternArray = pattern.c_str();
	
	int stringLength = string.length();
	int patternLength = pattern.length();
	
	int patternHash = hash(patternArray, 0, patternLength, patternLength, '\0', '\0', 0);	
	int currentHash = hash(stringArray, 0, patternLength, patternLength, '\0', '\0', 0);
	
	for (int counter = 0; counter < stringLength; counter++) {
		if (counter > 0) {
			currentHash = hash(stringArray, counter, counter+patternLength, patternLength, stringArray[counter - 1], stringArray[counter + patternLength - 1], currentHash);
		}
		if (currentHash == patternHash) {
			int subCounter = 0;
			for (int j = counter; j < (counter + patternLength); j++) {
				if (stringArray[j] != patternArray[subCounter]) {
					break;
				}
				if (subCounter == patternLength - 1 && stringArray[j] == patternArray[subCounter]) {
					return true;
				}
				subCounter++;
			}
		}
	}

	return false;
}