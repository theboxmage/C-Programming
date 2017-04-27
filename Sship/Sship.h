#include <iostream>
#include <queue>
#include <string>
#include <random>

using std::string;

class sship
{
	public:
		sship(int i, int m, int fire, int h, std::default_random_engine keepgen)
		{
			gen = keepgen;
			id = i;
			manability = m;
			firep = fire;
			hits = h;
			if(id == 1)
			{
				stype = "Xwing";
			}
			else if(id == 2)
			{
				stype = "Starfighter";
			}

		}
		int getID(){ return id; }
		int getManability(){ return manability; }
		int getfirep(){ return firep; }
		int getId(){ return id; }
		
		/**
		* Returns true if the ship is destroyed.
		**/
		bool git(){ hits--; /*std::cout << "Ship " << stype << " has " << hits << " health. " << std::endl;*/ return hits==0;}
		
		bool fight(sship & tohit, double damage)
		{
			bool answer = false;
			if(damage > tohit.getManability())
			{
				answer = tohit.git();
			}
			return answer;
		}
		
	private:
	std::default_random_engine gen;
	int manability;
	int firep ;
	int hits;
	int id;
	string stype;
};