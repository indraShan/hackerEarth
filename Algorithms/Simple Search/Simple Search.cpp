#include <iostream> 

int main() {
	
	int cases = 0;
	std::cin >> cases;
	
	long long numbers[cases];
	for (int counter = 0; counter < cases; counter++) {
		std::cin >> numbers[counter];
	}
	
	long long k = 0;
	std::cin >> k;
	
	for (int counter = 0; counter < cases; counter++) {
		if (numbers[counter] == k) {
			std::cout << counter << std::endl;
			break;
		}
	}
	
	return 0;
}