#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::string s;
		int a = 0, b = 0, n = 0;
		std::cin >> a >> b >> s;
		n = a + b;
		for (int k = 0; k < n; k++) {
			if (s[k] == '1') {
				b -= 1;
			}
			if (s[k] == '0') {
				a -= 1;
			}
		}
 
		int flag = 0;
		for (int j = 0; j < n / 2; j++) {
			if (s[j] != s[n - j - 1]) {
				if (s[j] == '?' and s[n - j - 1] == '0') {
					s[j] = s[n - j - 1];
					a -= 1;
				}
				if (s[j] == '?' and s[n - j - 1] == '1') {
					s[j] = s[n - j - 1];
					b -= 1;
				}
				if (s[n - j - 1] == '?' and s[j] == '0') {
					s[n - j - 1] = s[j];
					a -= 1;
				}
				if (s[n - j - 1] == '?' and s[j] == '1') {
					s[n - j - 1] = s[j];
					b -= 1;
				}
				if ((s[n - j - 1] == '1' and s[j] == '0') or (s[n - j - 1] == '0' and s[j] == '1')) {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1) {
			std::cout << -1 << std::endl;
			continue;
		}
		for (int j = 0; j < n / 2; j++) {
			if (s[j] == '?' and s[n - j - 1] == '?') {
				if (a >= b) {
					a -= 2;
					s[j] = '0';
					s[n - j - 1] = '0';
				}
				else if (b >= a) {
					b -= 2;
					s[j] = '1';
					s[n - j - 1] = '1';
				}
			}
		}
		if (n % 2 != 0 and s[n / 2] == '?') {
			if (a > b) {
				a -= 1;
				s[n / 2] = '0';
			}
			if (b > a) {
				b -= 1;
				s[n / 2] = '1';
			}
		}
		if (a == 0 and b == 0) {
			std::cout << s << std::endl;
		}
		else {
			std::cout << -1 << std::endl;
		}
	}
	return 0;
}
