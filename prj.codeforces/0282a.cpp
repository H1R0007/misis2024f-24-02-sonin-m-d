#include <iostream>
#include <string>
int main()
{
	int X = 0;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::string slovo;
		std::cin >> slovo;
		if (slovo.find("++") != slovo.npos)
			X += 1;
		else
			X -= 1;
	}
	std::cout << X << std::endl;
	return 0;
}
