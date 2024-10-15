#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k;
		std::string s, ans = "YES";
		std::cin >> n >> k >> s;
		std::vector<int> povtor(k, -1);
		for (int j = 0; j < n; j++) {
			if (s[j] == '1') {
				if (povtor[j % k] == 0) {
					ans = "NO";
					break;
				}
				else if (povtor[j % k] == -1) {
					povtor[j % k] = 1;
				}
			}
			else if (s[j] == '0') {
				if (povtor[j % k] == 1) {
					ans = "NO";
					break;
				}
				else if (povtor[j % k] == -1) {
					povtor[j % k] = 0;
				}
			}
		}
		if (std::count(povtor.begin(), povtor.end(), -1) == 0) {
			if (std::count(povtor.begin(), povtor.end(), 0) == k / 2 and std::count(povtor.begin(), povtor.end(), 1) == k / 2 and ans != "NO") {
				ans = "YES";
			}
			else {
				ans = "NO";
			}
		}
		if (std::count(povtor.begin(), povtor.end(), 0) > k / 2 or std::count(povtor.begin(), povtor.end(), 1) > k / 2) {
			ans = "NO";
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
