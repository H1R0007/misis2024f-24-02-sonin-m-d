#include <iostream>
#include <algorithm>
 
int main() {
	int t, n, el;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> n;
		int dlina = 0, mxdlina = 0;
		for (int j = 0; j < n; j++) {
			std::cin >> el;
			if (el == 0) {
				dlina += 1;
				if (mxdlina < dlina)
					mxdlina = dlina;
			}
			else
				dlina = 0;
		}
		std::cout << mxdlina << std::endl;
	}
	return 0;
}
