#include<iostream>
 
int main() {
    int t, a, b, c;
    std::cin >> t;
    while (t--) {
        std::cin >> a >> b >> c;
        std::cout << (a + c) % 2 << '\n';
    }
    return 0;
}
