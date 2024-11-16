#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int t = 0;
	std::cin >> t;
	for (int j = 0; j < t; j++) {
		int n = 0, c = 0, itog = 0;
		std::cin >> n;
		std::vector<int> S(n);
		for (int i = 0; i < n; i++) {
			std::cin >> S[i];
		}
		if (std::count(S.begin(), S.end(), 0) == n) {
			itog = 0;
		}
		else {
			std::sort(S.begin(), S.end());
			for (int i = 1; i < n; i++) {
				if (S[i] == S[i - 1] and S[i] != 0) {
					c = 1;
					break;
				}
			}
			if (std::count(S.begin(), S.end(), 0) == 0 and c == 0) {
				itog = S.size() + 1;
			}
			else if (std::count(S.begin(), S.end(), 0) == 0 and c == 1) {
				itog = S.size();
			}
			else if (std::count(S.begin(), S.end(), 0) == 1) {
				itog = S.size() - 1;
			}
			else if (std::count(S.begin(), S.end(), 0) > 1) {
				itog = S.size() - std::count(S.begin(), S.end(), 0);
			}
		}
		std::cout << itog << std::endl;
	}
	return 0;
}