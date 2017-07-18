#include <iostream>

using  std::cout;
using  std::cin;
using  std::endl;

void processProfilePhoto(int L, int W, int H);

int main() {
	int L;
	cin >> L;
	
	int N;
	cin >> N;
	
	
	for (int counter = 0; counter < N; counter++){ 
		int W;
		int H;
		cin >> W;
		cin >> H;
		processProfilePhoto(L, W, H);
	}
	
	return 0; 
}

void processProfilePhoto(int L, int W, int H) {
	if (W < L || H < L) {
		cout << "UPLOAD ANOTHER" << endl;
	}
	else if (W != H) {
		cout << "CROP IT" << endl;
	}
	else {
		cout << "ACCEPTED" << endl;
	}
}