#include <iostream>
#include <cmath>
 
int main()
{
    int t;
    std::cin >> t;
    while (t--) {
        int l = 0, r = 0, L = 0, R = 0;
        std::cin >> l >> r >> L >> R;
 
        if (((L == l) and (R == r)))
            std::cout << R - L << std::endl;
 
        else if ((r + 1 == L) or (R + 1 == l))
            std::cout << 1 << std::endl;
 
        else if ((l > L) and (r < R))
            std::cout << r - l + 2 << std::endl;
 
        else if ((L > l) and (R < r))
            std::cout << R - L + 2 << std::endl;
 
        else if (((l == L) and (r < R)) or ((L == l) and (R < r)))
            std::cout << std::abs(std::min(r, R) - L) + 1 << std::endl;
 
        else if (((r == R) and (l > L)) or ((R == r) and (L > l)))
            std::cout << std::abs(std::max(L, l) - R) + 1 << std::endl;
 
        else if ( ((l < L) and (r == L) and (r < R)) )
            std::cout << r - L + 2 << std::endl;
 
        else if (((l < L) and (r > L) and (r < R)))
            std::cout << r - L + 2 << std::endl;
 
        else if (((L < l) and (R == l) and (R < r)))
            std::cout << R - l + 2 << std::endl;
 
        else if (((L < l) and (R > l) and (R < r)))
            std::cout << R - l + 2 << std::endl;
 
        else
            std::cout << 1 << std::endl;
    }
    return 0;
}
 
