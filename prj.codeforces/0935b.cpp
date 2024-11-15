#include <iostream>
#include <string>
#include <vector>

int main() {
	int n = 0, x = 0, y = 0, itog = 0, c1 = 0, c2 = 0; 
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		char h = ' ';
		std::cin >> h;
		if (h == 'R') {
			x += 1;
			if (x == y) {
				c1 = y;
			}
		}
		else {
			y += 1;
			if (x == y) {
				c2 = x;
			}
		}
		if (x != y && c1 != 0) {
			if (y > c1) {
				c1 = 0;
			}
			else {
				itog += 1;
				c1 = 0;
			}
		}
		else if (x != y && c2 != 0) {
			if (x > c2) {
				c1 = 0;
			}
			else {
				itog += 1;
				c2 = 0;
			}
		}
	}
	std::cout << itog;
	return 0;
}