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
		for (int i = 0; i < n; i++) {
			for (int i1 = 0; i1 < m; i1++) {
				if (spis[i][i1] == 'R') {
					minx = std::min(minx, i);
					miny = std::min(miny, i1);
				}
			}
		}
		if (spis[minx][miny] == 'R') {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}