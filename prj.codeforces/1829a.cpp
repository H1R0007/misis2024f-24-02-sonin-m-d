#include <iostream>
#include <string>
 
int main() {
	int t;
	std::string s = "codeforces";
	std::string slovo;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> slovo;
		int itog  = 0;
		for (int j = 0; j < slovo.size(); j++) {
			if (slovo[j] != s[j])
				itog += 1;
		}
		std::cout << itog << std::endl;
	}
	return 0;
}
