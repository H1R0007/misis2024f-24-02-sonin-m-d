#include <iostream>
#include <vector>
#include <algorithm>
 
int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) { // перебор всех случаев данных
		int n, c1 = 1000000, c2 = 1000000, c3 = 1000000;
		std::vector<int> vremya, navik;
		std::cin >> n; // количество доступных книг
		for (int j = 0; j < n; j++) { // перебор всех доступных книг в 1ом наборе 
			int mi, si12; // сколько минут на изучение книги mi
			std::cin >> mi >> si12;
			vremya.push_back(mi);
			navik.push_back(si12);
		}
		for (int a1 = 0; a1 < vremya.size(); a1++) {
			if (vremya[a1] < c1 and navik[a1] == 10) {
				c1 = vremya[a1];
			}
			else if (vremya[a1] < c2 and navik[a1] == 1) {
				c2 = vremya[a1];
			}
			else if (vremya[a1] < c3 and navik[a1] == 11) {
				c3 = vremya[a1];
			}
			else
				continue;
		}
		if (c3 == 1000000 and (c1 == 1000000 or c2 == 1000000))
			std::cout << -1 << std::endl;
		else if (c1 + c2 > c3)
			std::cout << c3 << std::endl;
		else if (c3 > c1 + c2)
			std::cout << c1 + c2 << std::endl;
		else if (c1 + c2 == c3 and (c1 != 1000000 and c1 + c2 != 1000000)) {
			std::cout << c1 + c2 << std::endl;
		}
	}
	return 0;
}
