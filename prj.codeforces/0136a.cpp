#include <iostream>
#include <vector>
int main() {
    int n;
    std::cin >> n;

    std::vector<int> gifts(n + 1);
    for (int i = 0; i < n; i++) {
        int a = 0;
        std::cin >> a;
        gifts[a - 1] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        std::cout << gifts[i] << " ";
    }
    return 0;
}
