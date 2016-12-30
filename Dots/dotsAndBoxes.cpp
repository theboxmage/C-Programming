#include <iostream>

#include "box.h"

using namespace std;

int main()
{
	cout << "What size grid would you like? (2..9) ";
	string i = "";
	cin >> i;
	cin.ignore();
	while(i < "2" || i > "9")
	{
		cout << "Sorry, try again.";
		cin >> i;
		cin.ignore();
	}
	Box hold = Box(i.at(0)-'0');
	int iX = i.at(0)-'0';
	hold.printer();
	hold.printScore();
	cout << endl;
	string input;
	int holdScore = 0;
	cout << "What two dots would you like to connect? (Q to quit) ";
	getline(cin, input);
	bool flag = true;
	while(input != "q" && input != "Q")
	{
		int FTEST = hold.getPlayerScore()+hold.getAIScore();
		if(FTEST != iX*iX)
		{
			if(flag)
			{	
				if(input.length() < 4)
				{
					cout << "Sorry, try again. " << endl << endl;
					hold.printer();
					hold.printScore();
					cout << endl;
				}
				else
				{
					bool test = hold.update(input, 'H');
					while(holdScore!=hold.getPlayerScore())
					{
						holdScore=hold.getPlayerScore();
						
						input = "";
						while(input.length() < 4)
						{
							hold.printer();
							hold.printScore();
							cout << endl;
							cout << "Nice Score! Go again!";
							getline(cin, input);

						}
						bool check=hold.update(input, 'H');
						while(!check)
						{
							input = "";
							while(input.length() < 4)
							{
								hold.printer();
								hold.printScore();
								cout << endl;
								cout << "Nice Score! Go again!";
								getline(cin, input);
							}
							check = hold.update(input, 'H');
						}
						if(FTEST!=iX*iX)
						{
							break;
						}
					}
					if(!test)
					{
						cout << endl << "Try again:" << endl;
						hold.printer();
						hold.printScore();
						cout << endl;
					
					}
					else
					{
						hold.printer();
						hold.printScore();
			
						hold.AIMove();
					}
				}		
				cout << endl;
				if(hold.getPlayerScore()+hold.getAIScore() < iX*iX)
				{
					cout << "What two dots would you like to connect? (Q to quit) ";
					getline(cin, input);
				}
			}	
			else
			{
				input = 'q';
			}
		}
		else
		{
			input = 'q';
		}
	}
	
	
	hold.printer();
	cout << endl;
	cout << "\nFinal Score:" << endl << "  You: " << hold.getPlayerScore();
	cout << endl << "  Me: " << hold.getAIScore() << endl;
	if(hold.getPlayerScore() == hold.getAIScore())
	{
		cout << "I think we need a rematch.";
	}
	else if(hold.getPlayerScore() > hold.getAIScore())
	{
		cout << "Congratulations!";
	}
	else
	{
		cout << "Better luck next time";
	}
	
}