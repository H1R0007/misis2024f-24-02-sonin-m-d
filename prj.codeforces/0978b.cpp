#include <iostream>
#include <string>
 
int main()
{
	int spis[100];
	std::string stroka;
	int n, c = 0, kolvo = 0;
	std::cin >> n >> stroka;
	for (int i = 0; i < n; i++) {
		if (stroka[i] == 'x') {
			c += 1;
			if (c == 3) {
				kolvo += 1;
				c = 2;
			}
		}
		else {
			c = 0;
		}
	}
	std::cout << kolvo;
	return 0;
}
