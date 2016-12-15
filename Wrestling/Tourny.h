#include <iostream>
#include <iomanip>


class Tourny{
public:
	Tourny(std::default_random_engine g, std::list<Team> &t)
	{
		for(int i = 0; i < 20; i++)
		{
			for(int j = 0; j < 20; j++)
			{
				for(int k = 0; k < 12; k++)
				{
					recordbook[i][j][k] = 0;
				}
			}
		}
		for(int i = 0; i < 20; i++)
		{
			Scores[i] = 0;
		}
		gen = g;
		teams = t;
		std::list<Team>::iterator teamitr;
	}
	//714 96 1606 103
	void teamfight(Team &t1, Team &t2)
	{
		std::cout << std::endl << "Teams: " << t1.returnIDE() << " and " << t2.returnIDE() << std::endl;
		for(int i = 0; i < 12; i++)
		{
			Wrestler w1 = t1.returnByClass(i);
			Wrestler w2 = t2.returnByClass(i);
			int winner = bout(w1, w2, i);
			if(winner/100 == t1.returnIDE())
			{
				t1.increaseAP(w1.getWeightClass());
			}
		}
	}
	
	void printScore()
	{
		for(int i = 0; i < 20; i++)
		{
			std::cout << "Team " << i+1 << " has a score of: " << Scores[i] << std::endl;
		}
	}
    
	void printPage(int cla)
	{
		for(int i = 0; i < 20; i++)
		{
			for(int j = 0; j < 20; j++)
			{
				std::cout << std::setw(2) << recordbook[i][j][cla];
			}
			std::cout << std::endl;
		}
	}
	
	int bout(Wrestler &w1, Wrestler &w2, int cla)
	{
		std::normal_distribution <double> w1dist(w1.getAb(),15);
		std::normal_distribution <double> w2dist(w2.getAb(),15);
		//std::cout << std::endl;
		double w1S = w1dist(gen);
		double w2S = w2dist(gen);
		if(w1.getID()==-1 && w2.getID()==-1)
		{
			std::cout << "Neither team had a member in this weight class!" << std::endl;
			return -1;
		}
		else if(w1.getID()==-1)
		{
			std::cout << "Wrestler "<< w2.getID() << " Wins by default!" << std::endl;
			return -1;
		}
		else if(w2.getID()==-1)
		{
			std::cout << "Wrestler "<< w1.getID() << " wins by default!" << std::endl;
			return -1;
		}
		else if(w1S > w2S)
		{
			std::cout << "Wrestler " << w1.getID() << " vs. " << w2.getID() << ": ";
			std::cout << "Wrestler " << w1.getID() << " won!" << std::endl;
			double hold = (w1S - w2S)/15.0;
			if(hold<0.75)
			{
				Scores[(w1.getID()/100)-1] += 3;
			}
			else if(hold < 1.0)
			{
				Scores[(w1.getID()/100)-1] += 4;
			}
			else if(hold<1.5)
			{
				Scores[(w1.getID()/100)-1] += 5;
			}
			else
			{
				Scores[(w1.getID()/100)-1] += 6;
			}
			recordbook[w1.getID()/100-1][w2.getID()/100-1][cla]++;
			recordbook[w2.getID()/100-1][w1.getID()/100-1][cla]--;
			return w1.getID();
		}
		else if(w1S < w2S)
		{
			std::cout << "Wrestler " << w1.getID() << " vs. " << w2.getID() << ": ";
			std::cout << "Wrestler " << w2.getID() << " won!" << std::endl;
			double hold = (w2S - w1S)/15.0;
			if(hold<0.75)
			{
				Scores[(w2.getID()/100)-1] += 3;
			}
			else if(hold < 1.0)
			{
				Scores[(w2.getID()/100)-1] += 4;
			}
			else if(hold<1.5)
			{
				Scores[(w2.getID()/100)-1] += 5;
			}
			else
			{
				Scores[(w2.getID()/100)-1] += 6;
			}
			recordbook[w1.getID()/100-1][w2.getID()/100-1][cla]--;
			recordbook[w2.getID()/100-1][w1.getID()/100-1][cla]++;
			return w2.getID();
		}
		else
		{
			std::cout << "It was a tie" << std::endl;
		}
	}
	
	void startTourny(std::list<Team> teams)
	{
		std::list<Team>::iterator litr = teams.begin();
		//Pushing into an array[8][12] for sorting by seed.
		std::list<product> wrestlers[12];
		for(int x = 0; x < 12; x++)
		{
			litr = teams.begin();
		for(int i = 0; i < 8; i++)
		{
			product newpro;
			Wrestler toSeed = litr->returnByClass(x);
			newpro.w=toSeed;
			newpro.score=x*i;
			wrestlers[x].push_back(newpro);
			litr++;
		}
		}
		
		for(int holdid = 0; holdid < 12; holdid++)
		{
			wrestlers[holdid].sort();
			std::list<product>::iterator testir = wrestlers[holdid].begin();
			while(testir != wrestlers[holdid].end())
			{
				testir->w.print();
				testir++;
			}
			std::cin.ignore();
		}
		
	}
private:
	int Scores[20];
	int recordbook[20][20][12];
	std::default_random_engine gen;	
	std::list<Team> teams;
	struct product {
		Wrestler w;
		int score;
	  	bool operator< ( product &p1)
		{
			return (w.getID() < p1.w.getID());
		}
	} ;
};
