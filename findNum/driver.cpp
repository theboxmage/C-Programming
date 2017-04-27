#include <iostream>



bool equals(int n1, int n2)
{
	std::cout << "N1: " << n1 << " N2: " << n2 << std::endl;
	int hold = 0;
	while(n2 != 0)
	{
		hold = hold*10 + n2%10;
		n2 = n2/10;
	}
	return n1 == hold;
}

void print(bool a)
{
	if(a)
	{
		std::cout << "True" << std::endl;
	}
	else
	{
		std::cout << "False" << std::endl;
	}
}
int main()
{
	int i = 0;

	while(i < 100000)
	{
		int hold = 0;
		int n2 = i;
		while(n2 != 0)
		{
			hold = hold*10 + n2%10;
			n2 = n2/10;
		}
		if(equals(i*4, hold));
		i++;
	}
}
