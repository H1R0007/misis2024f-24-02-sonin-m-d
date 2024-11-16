#include <iostream>
#include <vector>

int main() {
	int t;
	std::cin >> t;
	for (int j = 0; j < t; j++) {
		int n = 0;
		std::cin >> n;
		std::vector<int> S(n);
		int f = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			std::cin >> S[i];
			sum += S[i];
		}
		for (int i = 0; i < n; i++) {
			if (S[i] == 1) {
				f = i;
			}
			else if (S[i] == 0) {
				break;
			}
		}
		int c = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (S[i] == 1) {
				c = i;
			}
			else if (S[i] == 0) {
				break;
			}
		}
		if (sum == n) {
			std::cout << 0 << std::endl;
		}
		else {
			std::cout << c - f << std::endl;
		}
	}
	return 0;
}