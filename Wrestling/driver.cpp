#include <iostream>
#include <list>
#include <random>
#include <ctime>
#include "Team.h"
#include "Tourny.h"
#include <iomanip>

using namespace std;

list<Team> Teams;
list<Team>::iterator litr;
list<Team>::iterator litr2;
int S[20][20];
void makeSchedule();
void printSchedule();

int main()
{
	default_random_engine gen(time(NULL));
	for(int i = 1; i < 21; i++)
	{
		//Team * teamptr = new Team(i, gen);
		Teams.push_back(Team(i, gen));
	}
	Tourny conf = Tourny(gen, Teams);
	makeSchedule();
	printSchedule();
	cout << endl << endl;
	for(int x = 1; x < 17; x++)//813 115 1409 120
	{
		cout << "Press enter to start Week: " << x << endl;
		cin.ignore();
		int holder = x;
		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 20; j++)
			{
				if(S[i][j] == holder)
				{
					litr = Teams.begin();
					advance(litr, i);
					litr2 = Teams.begin();
					advance(litr2, j);
					conf.teamfight(*litr, *litr2);
					
					S[i][j] = 0;
					S[j][i] = 0;
				}
			}
		}
		if(x == 5)
		{
			uniform_int_distribution <int> Idist(0, 19);
			int holdarray[8] = {0, 0, 0, 0, 0, 0, 0, 0};
			cout << endl << "Press enter to start the first tournament!" << endl;
			cin.ignore();
			list<Team> tourny1;
			litr=Teams.begin();
			int x;
			while(tourny1.size() < 8)
			{
				bool test = true;
				int k = Idist(gen);
				
				for(int z = 0; z < 8; z++)
				{
					if(holdarray[z] == k)
					{
						test= false;
					}
				}
				if(test)
				{
					holdarray[x] = k;
					litr=Teams.begin();
					advance(litr, k);
					tourny1.push_back(*litr);
					x++;
				}
			}
			list<Team>::iterator lister = tourny1.begin();
			cout << "The teams entering the tournament are: " << endl;
			while(lister!=tourny1.end())
			{
				cout << lister->returnIDE() ;
				lister++;
				if(lister!=tourny1.end())
				{
					cout << ", ";
				}
			}	
			cout << endl << endl;
			conf.startTourny(tourny1);
		}
	}
	//printSchedule();
	//conf.printPage(5);

}

void makeSchedule()
{
    default_random_engine gen(time(NULL));

    uniform_int_distribution<int> cwdist(1,16);   ///fifteen weeks
    uniform_int_distribution<int> tdist(8, 19);  ///random non conf team
    //int S[20][20];///20 teams, for 16 weeks
    for(int r=0; r<20; r++)
    {
        for(int c=0; c<20; c++)
        {
            if(r==c){S[r][c]=-1;}
            else {S[r][c]=0;}
        }
    }

///schedule is initialized
int w;
int row, col;
bool cont=true;
bool found=false;
        for(int r=0; r<8; r++)
        {
            for(int c=0; c<8; c++)
            {

                    if(S[r][c]==0)
                    {///find a new week number
                    while(S[r][c]==0){
                        found=false;
                        w = cwdist(gen);
                        //cout<<"checking week: "<<w;
                        //cout<<" at grid "<<r<<", "<<c<<endl;


                        ///row = my row r
                        row = r;
                        ///checking all columns to my left
                        for( col=0; col<c; col++)
                        {
                           if(S[row][col]==w){found = true;}
                        }
                        ///check ALL rows above me in my column
                        for(row=0; row<r; row++)
                        {
                            if (S[row][c]==w){found = true;}
                        }
                        ///if it was not found..then continue is false
                        if(found == false)
                        {
                            S[row][col]=w;
                            S[col][row]=w;
                         }
                    }
                 }
            cont=true;
            }
        }
        cout<<"Below is the schedule for dual meets."<<endl;
        int team;
        for(int r = 0; r<8; r++)///conference teams only
        { cont = true;
            for(int ct=0; ct<8; ct++)  ///ct = count of opponents to be scheduled
            {

               while(cont)
               { ///choose a random, unassigned team
               team = tdist(gen);   ///team number 8 to 19
               if(S[r][team]==0){
                                 cont = false;}
               }
               int x = 0;
               cont = true;
               while(cont && x<1000)
               {        found=false;
                        w = cwdist(gen);

                        for( col=0; col<20; col++)
                        {
                           if(S[r][col]==w){found = true;}
                        }
                        for(row=0; row<20; row++)
                        {
                           if (S[row][team]==w){found = true;}
                        }
                        if(found == false){S[r][team]=w;
                                           S[team][r]=w;
                                           cont=false;
										  }
                     x++;
                    }
                 cont=true;
                 }
            }
}

void printSchedule()
{
	for( int row=0; row<8; row++)
    {
        for(int col=0; col<20; col++)
        {   if(row==col){cout<<setw(4)<<"*";}
            else{if(col!=7){cout<<setw(4)<<S[row][col];} 
                 else{cout<<setw(4)<<S[row][col]<<"|";}}
        }
        cout<<endl;
    }
}

