#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool isPalindrome(string input);

int main() {
	string input;
	
	getline(cin, input);
	
	bool ispal = isPalindrome(input);
	
	cout << ((ispal) ? "YES" : "NO") << endl;
	
	return 0;
}

bool isPalindrome(string input) {
	int length = input.length();
	
	for (int counter = 0; counter < length/2; counter++) {
		if (input[counter] != input[length - counter - 1]) {
			return false;
		}
	}
	
	return true;
}