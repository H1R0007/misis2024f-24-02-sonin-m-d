#include <iostream>
 
int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k, r, c;
		std::cin >> n >> k >> r >> c;
        int g = (r + c) % k;
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if ((x + y) % k == g) {
                    std::cout << "X";
                }
                else {
                    std::cout << ".";
                }
            }
            std::cout << std::endl;
        }
	}
	return 0;
}
