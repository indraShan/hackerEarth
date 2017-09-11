#include <iostream>
#include <string.h>

int main() {
	
	int cases = 0;
	std::cin >> cases;
	
	int transactions[cases];
	memset(transactions, 0, sizeof(transactions));
	
	for (int counter = 0; counter < cases; counter++) {
		std::cin >> transactions[counter];
	}
	
	
	for (int counter = 1; counter < cases; counter++) {
		transactions[counter] += transactions[counter - 1]; 
	}
	
	long long numberOfQueries = 0;
	std::cin >> numberOfQueries;
	
	long long queries[numberOfQueries];
	
	for (int counter = 0; counter < numberOfQueries; counter++) {
		std::cin >> queries[counter];
		
		int index = 0;
		for (; index < cases; index++) {
			if (transactions[index] >= queries[counter]) {
				std::cout << index + 1 << std::endl;
				break;
			}
		}
		if (index == cases) {
			std::cout << -1 << std::endl;
		}
	}
		
	
	return 0;
}