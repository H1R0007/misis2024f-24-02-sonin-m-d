#include <iostream>
#include <string>
 
int main()
{
    int n;
    std::string slovo;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> slovo;
        if (slovo.size() > 10)
            slovo = slovo[0] + (std::to_string(slovo.size() - 2)) + slovo[slovo.size() - 1];
        std::cout << slovo << std::endl;
        
    }
    return 0;
}
 
