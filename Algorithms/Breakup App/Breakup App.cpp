#include <iostream> 
#include <string>
#include <sstream>
#include <string.h>

int main() {
	int lines = 0;
	
	std::cin >> lines;
	std::cin.ignore(256, '\n');
	
	int dates[33];
	memset(dates, 0, sizeof(dates));
	
	bool datesFound = false;
	
	for (int counter = 0; counter < lines; counter++) {
		std::string input = "";
		getline(std::cin, input);
		
		int length = input.length();
		if (length == 0) {
			continue;
		}
		char sender = input[0];
		int multplier = 1;
		if (sender == 'G') {
			multplier = 2;
		}
		
		int position = 1;
		int date = 0;
		for (int index = length; index >= 0; index--) {
			if (input[index] >= 48 && input[index] <= 57) {
				date = date + (((int)input[index] - '0') * position);
				if (position >= 10) {
					if (date <= 31) {
						dates[date] = dates[date] + multplier;
						position = 1;
						datesFound = true;
						// std::cout << "Setting counter for date = " << date << std::endl;
						date = 0;
					}
				}
				else {
					position = position * 10;
				}
			}
		}
	}
	
	if (datesFound == true) {
		int max = -1;
		int index = 0;
		int secondMax = max;
		for (int counter = 0; counter < 33; counter++) {
			// std::cout << "Count of date = " << counter << " " << dates[counter] << std::endl;
			if (dates[counter] > max) {
				// std::cout << "Updating second max value " << std::endl;
				secondMax = max;
				max = dates[counter];
				index = counter;
			}
			else if (dates[counter] == max) {
				// std::cout << "Setting second max to " << max << std::endl;
				secondMax = max;
			}
		}
	
		if (max == secondMax) {
			index = -1;
		}
		
		if (index == 19 || index == 20) {
			std::cout << "Date" << std::endl;
		}
		else  {
			std::cout << "No Date" << std::endl;
		}
	}
	else {
		std::cout << "No Date" << std::endl;
	}

	
	return 0; 
} 