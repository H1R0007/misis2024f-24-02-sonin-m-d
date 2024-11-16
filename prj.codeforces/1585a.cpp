#include <iostream>
#include <vector>

int main() {
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0, itog = 1, itog1 = 0;
		std::cin >> n;
		std::vector<int> S(n);
		for (int j = 0; j < n; j++) {
			int a = 0;
			std::cin >> a;
			if (j == 0) {
				S[j] = a;
				if (a == 1) {
					itog += 1;
				}
				else {
					itog += 0;
				}
			}
			else {
				S[j] = a;
				if (a == 1 and S[j - 1] == 1) {
					itog += 5;
				}
				else if (a == 1) {
					itog += 1;
				}
				else if (a == 0 and S[j - 1] == 0) {
					itog1 = -1;
				}
			}
		}
		if (itog1 == -1) {
			std::cout << itog1 << std::endl;
		}
		else {
			std::cout << itog << std::endl;
		}
	}
	return 0;
}