#include <iostream>
#include <iomanip>
class Wrestler{
public:
	Wrestler()
	{
		id = -1;
		weight = -1;
		abilityScore = -1;
		cla = 0;
	}
	Wrestler(int i, int w, int ab){
		id = i;
		weight = w;
		abilityScore = ab;
	}
		~Wrestler(){};
	int getID(){return id;}
	int getWeight(){return weight;}
	int getAb(){return abilityScore;}
	int getWeightClass(){return cla;};
	void incrementAB(){abilityScore++;}
	void setWeightClass(int i){cla=i;};

	
	bool operator< ( Wrestler &c1)
	{
		return (weight < c1.getWeight());
	}
	void print(){//For testing.
		std::cout << std::setw(3) << "ID: " << std::setw(5)<< id << " | Weight: "<< std::setw(3) << weight << " | Ability Score: " << abilityScore << std::endl;
	}
private:
	int cla = 0;
	int weight;
	int id;
	int abilityScore;
};