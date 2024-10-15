#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
 
int main() {
	int n = 0, m = 0, Ai = 0, prosh = 1;
	long long ans = 0;
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		std::cin >> Ai;
		if (Ai > prosh) {
			ans += Ai - prosh;
			prosh = Ai;
		}
		else if (Ai < prosh) {
			ans += n - prosh + Ai;
			prosh = Ai;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
