#include <iostream>
 
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int ans = 0;
		int b = 0, p = 0, f = 0, h = 0, c = 0;
		std::cin >> b >> p >> f >> h >> c;
		if (b == 1)
			std::cout << 0 << std::endl;
		else if (b % 2 == 0) {
			if (c >= h) {
				while (f > 0 and b > 0) {
					b -= 2;
					f -= 1;
					ans += c;
				}
				while (p > 0 and b > 0) {
					b -= 2;
					p -= 1;
					ans += h;
				}
			}
			else if (h >= c) {
				while (p > 0 and b > 0) {
					b -= 2;
					p -= 1;
					ans += h;
				}
				while (f > 0 and b > 0) {
					b -= 2;
					f -= 1;
					ans += c;
				}
			}
			std::cout << ans << std::endl;
		}
		else if (b % 2 == 1) {
			b -= 1;
			if (c >= h) {
				while (f > 0 and b > 0) {
					b -= 2;
					f -= 1;
					ans += c;
				}
				while (p > 0 and b > 0) {
					b -= 2;
					p -= 1;
					ans += h;
				}
			}
			else if (h >= c) {
				while (p > 0 and b > 0) {
					b -= 2;
					p -= 1;
					ans += h;
				}
				while (f > 0 and b > 0) {
					b -= 2;
					f -= 1;
					ans += c;
				}
			}
			std::cout << ans << std::endl;
		}
	}
	return 0;
}
