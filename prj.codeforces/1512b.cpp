#include <iostream>
#include <cmath>

int main() {
	int t = 0;
	std::cin >> t;
	for (int q = 0; q < t; q++) {
		int n = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0, c = 0;
		std::cin >> n;
		for (int i1 = 0; i1 < n; i1++) {
			for (int i2 = 0; i2 < n; i2++) {
				char S = ' ';
				std::cin >> S;
				if (S == '*' and c == 0) {
					x1 = i2;
					y1 = i1;
					c = 1;
				}
				if (S == '*' and c == 1) {
					x2 = i2;
					y2 = i1;
				}
			}
		}
		int x3 = 0, y3 = 0, x4 = 0, y4 = 0;
		if (x1 == x2 and y1 != y2) {
			if (x1 - 1 < 0) {
				x3 = x1 + 1;
				y3 = y1;
				x4 = x2 + 1;
				y4 = y2;
			}
			else if (x1 + 1 == n) {
				x3 = x1 - 1;
				y3 = y1;
				x4 = x2 - 1;
				y4 = y2;
			}
			else {
				x3 = x1 - 1;
				y3 = y1;
				x4 = x2 - 1;
				y4 = y2;
			}
		}
		else if (x1 != x2 and y1 == y2) {
			if (y1 - 1 < 0) {
				x3 = x1;
				y3 = y1 + 1;
				x4 = x2;
				y4 = y2 + 1;
			}
			else if (y1 + 1 == n) {
				x3 = x1;
				y3 = y1 - 1;
				x4 = x2;
				y4 = y2 - 1;
			}
			else {
				x3 = x1;
				y3 = y1 - 1;
				x4 = x2;
				y4 = y2 - 1;
			}
		}
		else if (x1 != x2 and y1 != y2) {
			x3 = x1;
			y3 = y2;
			x4 = x2;
			y4 = y1;
		}
		for (int i1 = 0; i1 < n; i1++) {
			for (int i2 = 0; i2 < n; i2++) {
				if ((i1 == y1 and i2 == x1) or (i1 == y2 and i2 == x2) or (i1 == y3 and i2 == x3) or (i1 == y4 and i2 == x4)) {
					if (i2 + 1 == n) {
						std::cout << '*' << std::endl;
					}
					else {
						std::cout << '*';
					}
				}
				else {
					if (i2 + 1 == n) {
						std::cout << '.' << std::endl;
					}
					else {
						std::cout << '.';
					}
				}
			}
		}
	}
	return 0;
}