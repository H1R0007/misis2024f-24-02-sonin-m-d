#include <iostream>
#include <vector>
#include <string>


int main() {
    int t = 0;
    std::cin >> t;

    while (t--) {
        int n = 0, m = 0;
        std::cin >> n >> m;

        std::vector<std::string> stroka(n);
        for (int i = 0; i < n; i++) {
            std::cin >> stroka[i];
        }

        // Проверяем каждого робота на возможность безопасно добраться до (0, 0)
        bool canReach = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (stroka[i][j] == 'R') {
                    // Проверяем направление stroka(0, 0)
                    if ((i > 0 or j > 0)) {
                        bool safe = true;

                        // Проверяем сверху
                        if (i > 0 and stroka[i - 1][j] == 'R') {
                            safe = false;
                        }
                        // Проверяем слева
                        if (j > 0 and stroka[i][j - 1] == 'R') {
                            safe = false;
                        }

                        if (safe) {
                            canReach = true;
                        }
                    }
                    else {
                        // Если робот уже находится в (0, 0)
                        canReach = true;
                    }
                }
            }
        }

        if (canReach) {
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
