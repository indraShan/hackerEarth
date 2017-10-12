#include <iostream>

int main() {
	int N = 0;
	std::cin >> N;

	if (N == 1) {
		std::cout << "Yes" << std::endl;
		return 0;
	}
	// Number of edges in a tree == N-1 (every node except root has one incoming node).
	// When we sum degrees of all nodes - every edge gets counted twice. So dividing it 
	// by 2 should get us the number of edges in the graph.
	// If this value is == N-1, the graph is a tree.
	
	
	// Number of edges (N-1) === (degree_sum/2)
	// 2 * (N-1) == degree_sum

	int degree_sum = 0;
	for (int counter = 0; counter < N; counter++) {
		int degree = 0;
		std::cin >> degree;
		degree_sum += degree;
	}
	
	if (degree_sum == (N * 2) - 2) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}
	
	return 0;
}