#include <iostream>
#include <algorithm>
 
int main() {
	int t;
	std::cin >> t; //кол-во наборов входных данных
	for (int q = 0; q < t; q++) {
		int n, m, Sx, Sy, d;
		std::cin >> n >> m >> Sx >> Sy >> d;
		int x = 1, y = 1;
 
		if ((Sx + d >= n and Sy + d >= m) or (Sx - d <= 1 and Sy - d <= 1) or
			(Sx + d >= n and Sx - d <= 1) or (Sy + d >= m and Sy - d <= 1)) {
			std::cout << -1 << std::endl;
		}
		else {
			std::cout << std::abs(x - n) + std::abs(y - m) << std::endl;
		}
	}
	return 0;
}
