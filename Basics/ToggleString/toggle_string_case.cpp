#include <iostream>
using std::cout;
using std::string;
using std::endl;
using std::cin;

int main()
{
    string input;
    getline(cin, input);
	
    int length = input.length();
    
	for (int counter = 0; counter < length; counter++) {
		// If uppercase, add 32
        if (input[counter] >= 65 && input[counter] < 91) {
            input[counter] += 32;
        }
		// If lower case, substract 32.
        else if (input[counter] >= 97 && input[counter] < 123) {
            input[counter] -= 32;
        }
    }
    
    cout << input << endl;
    
    return 0;
}