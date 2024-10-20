#include <iostream>
#include <vector>
#include <algorithm>
 
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0, Ai = 0, c = 0, schet = 0, itog = 0;
		std::cin >> n;
		std::vector<int> a, b;
		for (int i = 0; i < n; i++) {
			std::cin >> Ai;
			a.push_back(Ai);
		}
		std::sort(a.begin(), a.end());
		c = a[a.size() - 1];
		schet = 0;
		for (int i = 0; i < n; i++) {
			if (schet == 0) {
				b.push_back(a[a.size() - 1]);
				schet += 1;
			}
			if (schet == 1) {
				b.push_back(a[0]);
			}
			itog += c - b[i];
		}
		std::cout << itog << std::endl;
	}
	return 0;
}
