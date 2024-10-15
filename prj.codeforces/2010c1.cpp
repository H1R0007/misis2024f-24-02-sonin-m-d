#include <iostream>
 
int main() {
	std::string s;
	std::cin >> s;
	int i = 0, j = 1;
	while (j < s.size()) {
		if (s[i] == s[j]) {
			i++;
			j++;
		}
		else { 
			j -= i - 1;
			i = 0; 
		}
	}
	if (i > j - i) {
		std::cout << "YES" << std::endl;
		std::cout << s.substr(0, i) << std::endl;
	}
	else std::cout << "NO" << std::endl;
}
