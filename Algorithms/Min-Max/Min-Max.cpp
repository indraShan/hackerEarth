#include <iostream>
#include <string.h>
#include <limits.h>

int main() {
	
	int cases = 0;
	
	long long totalSum = 0;
	
	std::cin >> cases;
	
	int input[cases];
	int output[cases];
	memset(output, 0, sizeof(output));
	
	// std::cout << "cases = " << cases << std::endl;
	
	for (int counter = 0; counter < cases; counter++) {
		std::cin >> input[counter];
		totalSum += input[counter];
	}

	// Interatively sum for each index.
	// for (int counter = 0; counter < cases; counter++) {
	// 	for (int subCounter = 0; subCounter < cases; subCounter++) {
	// 		if (counter == subCounter) {
	// 			continue;
	// 		}
	// 		output[counter] += input[subCounter];
	// 	}
	// }
	
	for (int counter = 0; counter < cases; counter++) {
		output[counter] = totalSum - input[counter];
	}
	
	
	
	// Insertion sort
	// for (int counter = 1; counter < cases; counter++) {
	// 	int key = output[counter];
	// 	int j = counter - 1;
	// 	while (j>=0 && output[j] > key) {
	// 		output[j+1] = output[j];
	// 		j--;
	// 	}
	// 	output[++j] = key;
	// }
	int max = 0;
	int min = INT_MAX;
	for (int counter = 0; counter < cases; counter++) {
		int value = output[counter];
		if (value > max) {
			max = value;
		}
		if (value < min) {
			min = value;
		}
	}

	std::cout << min << " " << max << std::endl;
	
	return 0;
}