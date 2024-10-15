#include <iostream>
#include <algorithm>
#include <vector>
 
int main()
{
	int kolvo = 0;
	std::vector<int> spis(51);
	std::vector<int> spis1(51);
	int n, chislo, ostat = 0;
	std::cin >> n;
	for (int i = n; i >= 0; i--) {
		std::cin >> chislo;
		spis[i] = chislo; // тут все числа с конца до начала, начиная с индекса 0
		}
	for (int j = 0; j < spis.size(); j++ ) {
		if (std::find(spis1.begin(), spis1.end(), spis[j]) == spis1.end()) {
			kolvo += 1;
			spis1[spis.size() - j] = spis[j];
		}
	}
	std::cout << kolvo - 1 << std::endl;
	for (int k = 0; k < spis1.size(); k++) {
		if (spis1[k] != 0)
			std::cout << spis1[k] << " ";
	}
	return 0;
}
