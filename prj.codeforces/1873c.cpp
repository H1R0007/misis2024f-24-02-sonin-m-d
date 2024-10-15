#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
 
int main() {
	int t = 0, ans = 0;
	std::cin >> t;
	std::string s;
	std::vector<std::vector<int>> spis{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
		{1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
		{1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
		{1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
		{1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
		{1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
		{1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
		{1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	for (int i = 0; i < t; i++) {
		ans = 0;
		for (int i1 = 0; i1 < 10; i1++) {
			std::cin >> s;
			for (int i2 = 0; i2 < 10; i2++) {
				if (s[i2] == 'X') {
					ans += spis[i1][i2];
				}
			}
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
