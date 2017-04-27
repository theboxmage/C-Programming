#include <iostream>
#include <random>
#include <queue>
#include <ctime>
#include "Sship.h"
using namespace std;

int main()
{
	int ID1D = 0;
	int ID2D = 0;
	int ID2and1D = 0;
	std::default_random_engine gen(time(NULL));
	for(int i = 0; i < 100; i++)
	{
		bool ship2 = false;
		bool ship1 = false;	
	
		sship ID1 = sship(1, 77, 80, 3, gen);
		sship ID2 = sship(2, 85, 66, 2, gen);
		
		while(!ship1 && !ship2)
		{
	
			std::normal_distribution <double> dist1(ID1.getfirep(),10);
			std::normal_distribution <double> dist2(ID2.getfirep(),10);
	
			ship2 = ID1.fight(ID2, dist1(gen));
			ship1 = ID2.fight(ID1, dist2(gen));
		}
		
		if(ship1 && ship2)
		{
			ID2and1D++;
		}
		else if(ship1)
		{
			ID1D++;
		}
		else
		{
			ID2D++;
		}
	}
	std::cout << "The Xwing won " << ID2D << " times." << std::endl;
	std::cout << "The Startfighter won " << ID1D << " times." << std::endl;
	std::cout << "Both ships died " << ID2and1D << " times." << std::endl;
}
