#include <iostream>
#include <random>

int main()
{
       	std::default_random_engine generator(time(NULL));
  	std::uniform_int_distribution<int> dist(0,9);
	for(int i = 0; i < 10; i++)
	{
	  std::cout << dist(generator) << std::endl;
	}
}
