
#include <iostream>
#include <cmath>
int main()
{
	int X, Y;
	int xod = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int n;
			std::cin >> n;
			if (n == 1)
			{
				X = i;
				Y = j;
			}
		}
	}
	if (X == 0 or X == 4)
		xod += 2;
	if (Y == 0 or Y == 4)
		xod += 2;
	if (X == 1 or X == 3)
		xod += 1;
	if (Y == 1 or Y == 3)
		xod += 1;
	std::cout << xod << std::endl;
	return 0;
}
