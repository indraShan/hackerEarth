#include <iostream>
using namespace std;

int main()
{
    string input;
    getline(cin, input);
    
    const char *array = input.c_str();
    int length = input.length();
    
    for (int counter = 0; counter < length; counter++) {
        if (array[counter] >= 65 && array[counter] < 91) {
            input[counter] += 32;
        }
        else if (array[counter] >= 97 && array[counter] < 123) {
            input[counter] -= 32;
        }
    }
    
    cout << input << endl;
    
    return 0;
}