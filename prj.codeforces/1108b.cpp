#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n = 0, x = 0, y = 0;
	std::vector<int> spis, dva;
	std::cin >> n;
	while (n--) {
		int cifra = 0;
		std::cin >> cifra;
		spis.push_back(cifra);
	}
	std::sort(spis.begin(), spis.end());
	x = spis[spis.size() - 1];
	if (std::count(spis.begin(), spis.end(), x) == 2) {
		std::cout << x << " " << x << std::endl;
	}
	else {
		for (int i = 0; i < spis.size() - 1; i++) {
			if (x % spis[i] == 0 and std::count(dva.begin(), dva.end(), spis[i]) == 0) {
				dva.push_back(spis[i]);
				spis[i] = 0;
			}
		}
		for (int i = 0; i < spis.size() - 1; i++) {
			if (spis[i] > y) {
				y = spis[i];
			}
		}
		std::cout << x << " " << y << std::endl;
	}
	return 0;
}
