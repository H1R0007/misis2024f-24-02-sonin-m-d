#include <iostream>
#include <vector>
#include <cmath>

int main() {
	int t = 0;
	std::cin >> t;
	for (int q = 0; q < t; q++) {
		int n = 0;
		std::cin >> n;
		std::vector<int> S(2 * n);
		std::vector<int> S1(n);
		for (int i = 0; i < n * 2; i += 2) {
			std::cin >> S[i] >> S[i + 1];
		}
		for (int i = 0; i < n; i++) {
			std::cin >> S1[i];
		}
		int c = 0;
		for (int i = 0; i < (n * 2) - 1; i += 2) {
			S[i] += (c + S1[i/2]);
			std::cout << S1[i / 2] + c << " " << std::endl;
			std::cout << S[i] << " - diff prib" << std::endl;
			if (S[i + 1] < S[i]) {
				c = 1 + (S[i] - S[i + 1]);
			}
			else {
				c = 0;
			}
		}
		std::cout << S[n * 2 - 2] << std::endl;
	}
	return 0;
}