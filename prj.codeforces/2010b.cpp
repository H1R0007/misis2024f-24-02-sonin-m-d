#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
 
int main() {
	int a, b, sum = 6;
	std::cin >> a >> b;
	if (sum - a - b == 2) {
		std::cout << 2;
	}
	if (sum - a - b == 3) {
		std::cout << 3;
	}
	if (sum - a - b == 1) {
		std::cout << 1;
	}
	return 0;
}
