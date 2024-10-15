#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int n, H, a, ans = 0;
		std::cin >> n >> H;
		std::vector<int> yron;
		for (int i = 0; i < n; i++) {
			int A;
			std::cin >> A;
			yron.push_back(A);
		}
		std::sort(yron.begin(), yron.end());
		int Y1 = yron[yron.size() - 1], Y2 = yron[yron.size() - 2], summa = Y1 + Y2, R = 0;
		ans = (H / summa) * 2;
		R = H % summa;
		if (R > Y1)
			ans += 2;
		if (R <= Y1 and R != 0)
			ans += 1;
		std::cout << ans << std::endl;
	}
	return 0;
}
