#include "Wrestler.h"
#include <vector>
#include <list>

class Team{
public:
	///ID is an x*100 value, so the 1-99 values will be empty for unique member ID.

	
	Team(int id, std::default_random_engine &gen)
	{
		for(int i = 0; i < 12; i++)
		{
			wres[i] = Wrestler();	
		}//100 std 15       152 40
		
		keepgen = gen;	
		std::uniform_int_distribution <int> Idist(10, 18);
		std::normal_distribution <double> ndist(100,15);
		std::normal_distribution <double> WeiDist(152, 30);
		int r= Idist(gen);
		ide =id;
		for(int i = 0; i < r; i++)
		{
			members.push_back(Wrestler(id*100+i+1, WeiDist(gen), ndist(gen)));
		}
		fillWeightClass();
		//displayByWeightClass();
	}
	
	void fillWeightClass()
	{
		std::list<Wrestler>::iterator itr;
		titr = members.begin();
		std::list<Wrestler> hold;
		while(titr!=members.end())
		{
			hold.push_back(*titr);
			titr++;
		}
		hold.sort();
		itr=hold.begin();
		
		int i = 0, x = -1;
		Wrestler hold1 = wres[0];
		while(itr->getWeight()<104 && itr!=hold.end())//93-104 
		{
			if(itr->getAb() > hold1.getAb() && itr->getWeight() > 92)
			{
				hold1 = *itr;
				hold1.setWeightClass(0);
				x = i;
			}
			i++;
			itr++;
		}
		if(x != -1)
		{
			itr = hold.begin();
			std::advance(itr, x);
			hold.erase(itr);
			wres[0]=hold1;
		}
		
		itr = hold.begin();
		i = 0;
		x = -1;
		hold1 = wres[1];
		while(itr->getWeight()<113 && itr!=hold.end())//93-112
		{
			if(itr->getAb() > hold1.getAb() && itr->getWeight() > 92)
			{
				hold1 = *itr;
				hold1.setWeightClass(1);
				x = i;
			}
			i++;
			itr++;
		}
		if(x != -1)
		{
			itr = hold.begin();
			std::advance(itr, x);
			hold.erase(itr);
			wres[1]=hold1;
		}
		
		itr = hold.begin();
		i = 0;
		x = -1;
		hold1 = wres[2];
		while(itr->getWeight()<119 && itr!=hold.end())//104-118
		{
			if(itr->getAb() > hold1.getAb() && itr->getWeight() > 103)
			{
				hold1 = *itr;
				hold1.setWeightClass(2);
				x = i;
			}
			i++;
			itr++;
		}
		if(x != -1)
		{
			itr = hold.begin();
			std::advance(itr, x);
			hold.erase(itr);
			wres[2]=hold1;
		}
		
		itr = hold.begin();
		i = 0;
		x = -1;
		hold1 = wres[3];
		while(itr->getWeight()<127 && itr!=hold.end())//119-126
		{
			if(itr->getAb() > hold1.getAb() && itr->getWeight() > 119)
			{
				hold1 = *itr;
				hold1.setWeightClass(3);
				x = i;
			}
			i++;
			itr++;
		}
		if(x != -1)
		{
			itr = hold.begin();
			std::advance(itr, x);
			hold.erase(itr);
			wres[3]=hold1;
		}
		
		itr = hold.begin();
		i = 0;
		x = -1;
		hold1 = wres[4];
		while(itr->getWeight()<133 && itr!=hold.end())//119-132
		{
			if(itr->getAb() > hold1.getAb() && itr->getWeight() > 118)
			{
				hold1 = *itr;
				hold1.setWeightClass(4);
				x = i;
			}
			i++;
			itr++;
		}
		if(x != -1)
		{
			itr = hold.begin();
			std::advance(itr, x);
			hold.erase(itr);
			wres[4]=hold1;
		}
		
		itr = hold.begin();
		i = 0;
		x = -1;
		hold1 = wres[5];
		while(itr->getWeight()<139 && itr!=hold.end())//127-138
		{
			if(itr->getAb() > hold1.getAb() && itr->getWeight() > 126)
			{
				hold1 = *itr;
				hold1.setWeightClass(5);
				x = i;
			}
			i++;
			itr++;
		}
		if(x != -1)
		{
			itr = hold.begin();
			std::advance(itr, x);
			hold.erase(itr);
			wres[5]=hold1;
		}
		
		itr = hold.begin();
		i = 0;
		x = -1;
		hold1 = wres[6];
		while(itr->getWeight()<146 && itr!=hold.end())//133-145
		{
			if(itr->getAb() > hold1.getAb() && itr->getWeight() > 133)
			{
				hold1 = *itr;
				hold1.setWeightClass(6);
				x = i;
			}
			i++;
			itr++;
		}
		if(x != -1)
		{
			itr = hold.begin();
			std::advance(itr, x);
			hold.erase(itr);
			wres[6]=hold1;
		}
		
		itr = hold.begin();
		i = 0;
		x = -1;
		hold1 = wres[7];
		while(itr->getWeight()<156 && itr!=hold.end())//139-155
		{
			if(itr->getAb() > hold1.getAb() && itr->getWeight() > 138)
			{
				hold1 = *itr;
				hold1.setWeightClass(7);
				x = i;
			}
			i++;
			itr++;
		}
		if(x != -1)
		{
			itr = hold.begin();
			std::advance(itr, x);
			hold.erase(itr);
			wres[7]=hold1;
		}
		
		itr = hold.begin();
		i = 0;
		x = -1;
		hold1 = wres[8];
		while(itr->getWeight()<168 && itr!=hold.end())//146-167
		{
			if(itr->getAb() > hold1.getAb() && itr->getWeight() > 145)
			{
				hold1 = *itr;
				hold1.setWeightClass(8);
				x = i;
			}
			i++;
			itr++;
		}
		if(x != -1)
		{
			itr = hold.begin();
			std::advance(itr, x);
			hold.erase(itr);
			wres[8]=hold1;
		}
		
		itr = hold.begin();
		i = 0;
		x = -1;
		hold1 = wres[9];
		while(itr->getWeight()<190 && itr!=hold.end())//156-189
		{
			if(itr->getAb() > hold1.getAb() && itr->getWeight() > 155)
			{
				hold1 = *itr;
				hold1.setWeightClass(9);
				x = i;
			}
			i++;
			itr++;
		}
		if(x != -1)
		{
			itr = hold.begin();
			std::advance(itr, x);
			hold.erase(itr);
			wres[9]=hold1;
		}
		
		itr = hold.begin();
		i = 0;
		x = -1;
		hold1 = wres[10];
		while(itr->getWeight()<213 && itr!=hold.end())//168-212
		{
			if(itr->getAb() > hold1.getAb() && itr->getWeight() > 167)
			{
				hold1 = *itr;
				hold1.setWeightClass(10);
				x = i;
			}
			i++;
			itr++;
		}
		if(x != -1)
		{
			itr = hold.begin();
			std::advance(itr, x);
			hold.erase(itr);
			wres[10]=hold1;
		}
		
		itr = hold.begin();
		i = 0;
		x = -1;
		hold1 = wres[11];
		while(itr->getWeight()<286 && itr!=hold.end())//190-285
		{
			if(itr->getAb() > hold1.getAb() && itr->getWeight() > 189)
			{
				hold1 = *itr;
				hold1.setWeightClass(11);
				x = i;
			}
			i++;
			itr++;
		}
		if(x != -1)
		{
			itr = hold.begin();
			std::advance(itr, x);
			hold.erase(itr);
			wres[11]=hold1;
		}
	}
	
	void display()
	{
		titr = members.begin();
		std::cout << "Team ID: " << titr->getID()/100 << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		while(titr!=members.end())
		{
			titr->print();
			titr++;
		}
		std::cout << std::endl;
	}
	
	int returnIDE(){return ide;}
	
	void increaseAP(int WCID)
	{
		wres[WCID].incrementAB();
	}
	
	void displayByWeightClass()
	{
		std::cout << "Team ID: " << ide << std::endl;
		for(int i=0; i < 12; i++)
		{
			wres[i].print();
		}
	}
	Wrestler returnByClass(int i){return wres[i];}
	
private:
	std::default_random_engine keepgen;
	int count;
	int ide;
	Wrestler wres[12];
	std::vector<Wrestler> weightClass;
	std::list<Wrestler> members;
	std::list<Wrestler>::iterator titr;
	void weightClasses();
};