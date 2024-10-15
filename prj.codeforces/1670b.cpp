#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0, k = 0, max = 0;
		std::vector<char> spisIZosob;
		std::vector<int> spisBEZosob;
		std::string s;
		char bukva;
		std::cin >> n >> s >> k;
		for (int q = 0; q < k; q++) {
			std::cin >> bukva;
			spisIZosob.push_back(bukva);
		}
		for (int j = 0; j < n; j++) {
			for (int j1 = 0; j1 < k; j1++) {
				if (s[j] == spisIZosob[j1]) {
					spisBEZosob.push_back(j);
					if (spisBEZosob.size() == 1)
						max = j;
					else if (j - spisBEZosob[spisBEZosob.size() - 2] > max){
						max = j - spisBEZosob[spisBEZosob.size() - 2];
					}
				}
			}
		}
		std::cout << max << std::endl;
	}
	return 0;
}
