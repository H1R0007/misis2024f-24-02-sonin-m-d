#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int ans = 0;
        int n;
        int x;
        std::cin >> n >> x;
        std::vector<int> a;
        for (int j = 0; j < n; j++) {
            int b;
            std::cin >> b;
            a.push_back(b);
        }
        while ((x > 0) or (std::find(a.begin(), a.end(), ans + 1) != a.end())) {
            if (std::find(a.begin(), a.end(), ans + 1) != a.end()) {
                ans += 1;
            }
            else 
            {
                x -= 1;
                ans += 1;
            }
        }
        std::cout << ans << std::endl;
    }
}
