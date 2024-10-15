#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
 
int main() {
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0, ans = 0;
		std::cin >> n;
		std::vector<int> spis;
		for (int j = 0; j < n; j++) {
			int a = 0;
			std::cin >> a;
			spis.push_back(a);
		}
		for (int k = 0; k < n; k += 2)
			ans += spis[k];
		for (int k = 1; k < n; k += 2)
			ans -= spis[k];
		std::cout << ans << std::endl;
	}
	return 0;
}
