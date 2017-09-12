#include <stdio.h>

int main () {
	
	int cases = 0;
	
	scanf("%d", &cases);
	
	
	char suvo[4] = {'S', 'U', 'V', 'O'};
	char suvojit[7] = {'S', 'U', 'V', 'O', 'J', 'I', 'T'};
	for (int counter = 0; counter < cases; counter++) {
		char input[150];
		int suvoCount = 0;
		int suvojitCount = 0;
		
		// input
		scanf("%s", input);
		
		// printf("Input = %s \n", input);
		
		int matchIndex = 0;
		int index = 0;
		int matchInProgress = 0;
		while (input[index] != '\0') {
			// Wait for S. 
			if (input[index] == suvo[0]) {
				// We have a new sequence start.
				// Reset matchIndex to 0, as anyway any previous 'find' is now
				// incorrect.
				matchIndex = 0;
				matchInProgress = 1;
			}
			if (matchIndex == 3) {
				// We found suvo;
				// printf("found suvo \n");
				suvoCount++;
			}
			else if (matchIndex == 6) {
				// We found suvojit.
				// printf("found suvojit \n");
				suvoCount--;
				suvojitCount++;
			}
			// We found char match. Increatement match index.
			if (matchInProgress && matchIndex <=3 && input[index] == suvo[matchIndex]) {
				matchIndex++;
			}
			else if (matchInProgress && matchIndex > 3 && matchIndex <= 7 && input[index] == suvojit[matchIndex]) { 
				matchIndex++;
			}
			else {
				matchInProgress = 0;
			}
			
			index++;
		}
		printf("SUVO = %d, SUVOJIT = %d", suvoCount, suvojitCount);
		printf("\n");
	}
	
	return 0;
}