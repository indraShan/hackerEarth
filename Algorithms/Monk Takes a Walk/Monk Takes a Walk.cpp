#include <iostream>
#include <string>

int main() {
	
	int cases = 0;
	
	std::cin >> cases;
	std::cin.ignore(256, '\n');
	
	for (int counter = 0; counter < cases; counter++) {
		std::string input = "";
		getline(std::cin, input);
		
		int length = input.length();
		int vowelsCount = 0;
		for (int index = 0; index < length; index++) {
			if (input[index] == 'A' || input[index] == 'E' || input[index] == 'I' || input[index] == 'O' || input[index] == 'U' || 
				input[index] == 'a' || input[index] == 'e' || input[index] == 'i' || input[index] == 'o' || input[index] == 'u') {
					vowelsCount++;
				}
 		}
		std::cout << vowelsCount << std::endl;
		
	}
	
	return 0;
}