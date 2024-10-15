#include <iostream>
 
int main()
{
	int n, k;
	int kolvo = 0;
	std::cin >> n >> k;
	int shet_now = 0, shet_k = 0 ;
	for (int i = 1; i <= n; i++)
	{
		if (i == k)
		{
			std::cin >> shet_k;
			if (shet_k > 0)
				kolvo += 1;
		}
		if (i != k)
		{
			std::cin >> shet_now;
			if (shet_now >= shet_k and shet_now > 0)
				kolvo += 1;
		}
 
	}
	std::cout << kolvo << std::endl;
	return 0;
}
