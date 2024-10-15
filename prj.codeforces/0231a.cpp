#include <iostream>
 
int main()
{
    int n, itog;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int P, V, T;
        std::cin >> P >> V >> T;
        if (P + V + T >= 2)
            itog += 1;
    }
    std::cout << itog;
    return 0;
}
