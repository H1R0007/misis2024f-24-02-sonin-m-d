#include <iostream>
#include <vector>
#include <cmath>

int main() {
	int t = 0;
	std::cin >> t;
	for (int j = 0; j < t; j++) {
		int n = 0;
		std::cin >> n;
		std::vector<int> prib(n);
		std::vector<int> otb(n);
		std::vector<int> op(n);
		std::vector<int> stoit(n);
		for (int i = 0; i < n; i++) {
			std::cin >> prib[i] >> otb[i];
			float f1 = otb[i], f2 = prib[i];
			stoit[i] = std::ceil((f1 - f2) / 2);
		}
		for (int i = 0; i < n; i++) {
			std::cin >> op[i];
		}
		int c = 0;
		for (int i = 0; i < n; i++) {
			prib[i] = prib[i] + op[i] + c;
			int j = 0;
			j = prib[i] + stoit[i];
			if (j > otb[i]) {
				c = j - otb[i];
			}
			else {
				c = 0;
			}
		}
		std::cout << prib[n - 1] << std::endl;
	}
	return 0;
}