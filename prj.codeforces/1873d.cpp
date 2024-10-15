#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
 
int main() {
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::string s;
		int n = 0, k = 0, ans = 0;
		std::cin >> n >> k >> s;
		for (int a1 = 0; a1 <= n; a1++) {
			if (s[a1] == 'B') {
				ans += 1;
				a1 += k - 1;
			}
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
