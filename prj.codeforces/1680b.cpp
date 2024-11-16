#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {
	int t = 0;
	std::cin >> t;
	for (int j = 0; j < t; j++) {
		int n = 0, m = 0;
		std::vector<std::string> spis;
		std::cin >> n >> m;
		for (int i = 0; i < n; i++) {
			std::string a = " ";
			std::cin >> a;
			spis.push_back(a);
		}
		int minx = 1000000;
		int miny = 1000000;
		for (int y = 0; y < n; y++) { // строки
			for (int x = 0; x < m; x++) { // столбцы
				if (spis[y][x] == 'R') {
					//std::cout << y << "- y; " << x << "- x; " << std::endl;
					miny = std::min(miny, y); //выбор минимальной коорд. строки с R в ней
					minx = std::min(minx, x); //выбор минимальной коорд. столбца с R в нём
				}
			}
		}
		//std::cout << minx << " - minx; " << miny << " - miny; " << std::endl;
		//std::cout << spis[miny][minx] << " - spis[miny][minx]; " << std::endl;
		if (spis[miny][minx] == 'R') {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}