#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string seatTypeForNumber(int number);

int main() {
	int cases;
	cin >> cases;
	
	for (int counter = 0; counter<cases; counter++) {
		int seatNumber;
		cin >> seatNumber;
		int targetSeatNo = -1; 
		string seatType = "";
		
		int remainder = seatNumber % 12;
		if (remainder == 0) {
			// Window seat (in the right bottom part)
			targetSeatNo = seatNumber - 11;
			seatType = "WS";
		}
		else if (remainder == 1) {
			// Window seat (in the left bottom part)
			targetSeatNo = seatNumber + 11;
			seatType = "WS";
		}
		else if (remainder == 6) {
			// Window seat. Top left.
			targetSeatNo = seatNumber + 1;
			seatType = "WS";
		}
		else if (remainder == 7) {
			// Window seat. Top right.
			targetSeatNo = seatNumber - 1;
			seatType = "WS";
		}
		else if (remainder < 6) {
			// Left lane
			int diff = 6 - (seatNumber % 6);
			targetSeatNo = seatNumber + (2 * diff) + 1;
			seatType = seatTypeForNumber(targetSeatNo);			
		}
		else {
			// Right lane.
			int diff = (seatNumber % 6);
			targetSeatNo = seatNumber - (2 * diff) + 1;
			seatType = seatTypeForNumber(targetSeatNo);
		}
		cout << targetSeatNo << " " << seatType << endl;
		
	}
	
	
	
	return 0;
}


string seatTypeForNumber(int number) {
	if (number % 3 == 2) {
		return "MS";
	}
	else if (number % 3 == 0 || number % 3 == 1) {
		return "AS";
	}
	return "";
}