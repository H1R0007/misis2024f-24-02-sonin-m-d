// 1872A
#include <iostream>
#include <cmath>
 
int main()
{
    int t, minX = 0;
    int a, b, c;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        std::cin >> a >> b >> c;
        if (a == b)
            std::cout << 0 << std::endl;
        else if (std::abs(b - a) <= 2 * c)
            std::cout << 1 << std::endl;
        else
        {
            for (int j = 4; j < 1000; j += 2)
            {
                if (std::abs(b - a) <= j * c)
                {
                    minX += j / 2;
                    std::cout << minX << std::endl;
                    minX = 0;
                    break;
                }
            }
        }
    }
    return 0;
}
