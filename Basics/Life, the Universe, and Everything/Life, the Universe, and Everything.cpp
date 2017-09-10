#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() { 
	
	while(true) {
		int input;
		cin >> input;
		if (input == 42) {
			break;
		}
		cout << input << endl;
	}
}