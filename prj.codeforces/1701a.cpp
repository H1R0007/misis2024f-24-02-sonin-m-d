#include <iostream>

int main() {
	int t = 0;
	std::cin >> t;
	for (int j = 0; j < t; j++) {
		int i = 0, i1 = 0, i2 = 0, i3 = 0;
		std::cin >> i >> i1 >> i2 >> i3;
		if (i + i1 + i2 + i3 == 0) {
			std::cout << 0 << std::endl;
		}
		if (i + i1 + i2 + i3 == 1 or i + i1 + i2 + i3 == 2 or i + i1 + i2 + i3 == 3) {
			std::cout << 1 << std::endl;
		}
		if (i + i1 + i2 + i3 == 4) {
			std::cout << 2 << std::endl;
		}
	}
	return 0;
}