#include <iostream>
#include <string>
#include <vector>

int main() {
	int t = 0;
	std::cin >> t;
	for (int j = 0; j < t; j++) {
		std::vector<std::string> S;
		for (int i = 0; i < 8; i++) {
			std::string s = " ";
			std::cin >> s;
			S.push_back(s);
		}
		int c = 0, r = 0;
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				if (S[y][x] == '#' and y != 0 and x != 0 and x != 7 and y != 7) {
					if (S[y - 1][x - 1] == '#' and S[y - 1][x + 1] == '#' and S[y + 1][x - 1] == '#' and S[y + 1][x + 1] == '#') {
						c = y + 1;
						r = x + 1;
					}
				}
			}
		}
		std::cout << c << " " << r << std::endl;
	}

	return 0;
}
