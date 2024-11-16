#include <iostream>
#include <string>

int main() {
	int t = 0;
	std::cin >> t;
	for (int j = 0; j < t; j++) {
		std::string S;
		std::cin >> S;
		std::string itog = "YES";
		if (S.size() == 1) {
			itog = "NO";
		}
		else {
			for (int i = 0; i < S.size(); i++) {
				if (i == 0) {
					if (S[i + 1] != S[i]) {
						itog = "NO";
					}
				}
				if (i == S.size() - 1) {
					if (S[i] != S[i - 1]) {
						itog = "NO";
					}
				}
				else if (i != 0) {
					if (S[i + 1] != S[i] and S[i - 1] != S[i]) {
						itog = "NO";
					}
				}
			}
		}
		std::cout << itog << std::endl;
	}
	return 0;
}