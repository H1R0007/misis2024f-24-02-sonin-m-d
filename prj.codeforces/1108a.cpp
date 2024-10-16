#include <iostream>

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int l1 = 0, r1 = 0, l2 = 0, r2 = 0, a = 0, b = 0, pr = 0;
		std::cin >> l1 >> r1 >> l2 >> r2;
		for (int i = 0; i < 1000000000; i++) {
			for (int j = 0; j < 1000000000; j++) {
				pr = j;
				a = l1 + i;
				if (l2 + j != a) {
					b = l2 + j;
					break;
				}
			}
			if (l2 + pr != a) {
				b = l2 + pr;
				break;
			}
		}
		std::cout << a << " " << b << std::endl;
	}
	return 0;
}
