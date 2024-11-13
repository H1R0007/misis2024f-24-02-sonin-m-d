#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n = 0, k = 0, mx = 0;
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int Ai = 0;
		std::cin >> Ai;
		if (k % Ai == 0 && k / Ai > mx) {
			mx = k / Ai;
		}
	}
	std::cout << mx << std::endl;
}