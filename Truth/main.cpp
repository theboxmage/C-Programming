#include <iostream>
#include <algorithm>
#include <list> 
#include <cmath>

using std::endl;
using std::string;
using std::cout;


std::list<char> inputs;

int find(char C) 
{
	std::list<char>::iterator litr = inputs.begin();
	int x = 0;
	while(litr!=inputs.end())
	{
		if(C==*litr)
		{
			return x;
		}
		x++;
		litr++;
	}
}

int findValue(int x, char letter)
{
	int y = 0;
	y = pow(10, (inputs.size()-1-find(letter)));
	int z = (x / y)%10;
	return z;
}

bool run1(int x, string input)
{
	//cout << "\nInput is " << input << endl;
	//Base Case: End.
	if(input.length() == 1)
	{
		return findValue(x, input.at(0));
	}
	if(input.length() == 2 && input.at(1) == '\'')
	{
		return !findValue(x, input.at(0));
	}
	//Working Case: (). 
	if(input.at(0) == '(')
	{
		//MADE HERE
		string leftside = "";
		int count = 1;
		int i;
		for(i = 1; i < input.length(); i++)
		{
			if(input.at(i) == ')')
			{
				count--;
				if(count == 0)
				{
					break;
				}
			}
			if(input.at(i) == '(')
			{
				count++;
			}
		}
		//cout << input.substr(1, i-1) << endl;
		//cout << input.substr(i+2) << endl;
		//cout << input.at(i+1) << endl;
		//cout << i;
		if(input.length()-1 == i)
		{
			return run1(x, input.substr(1, i-1));;
		}
		else if(input.at(i+1) == '\'')
		{
			if(input.length()-2 == i)
			{
				return !run1(x, input.substr(1, i-1));
			}
			else if(input.at(i+2) == '+')
			{
				return !run1(x, input.substr(1, i-1)) || run1(x, input.substr(i+3));
			}
			else if(input.at(i+2) == '*')
			{
				return !run1(x, input.substr(1, i-1)) && run1(x, input.substr(i+3));
			}
			else
			{
				cout << "ERROR: Output, unexpected symbol: " << input .at(i+1) << " Output may be skewed" << endl;
				return false;
			}
		}
		else if(input.at(i+1) == '+')
		{
			return run1(x, input.substr(1, i-1)) || run1(x, input.substr(i+2));
		}
		else if(input.at(i+1) == '*')
		{
			return run1(x, input.substr(1, i-1)) && run1(x, input.substr(i+2));
		}
		else
		{
			cout << "ERROR: Output, unexpected symbol: " << input .at(i+1) << " Output may be skewed" << endl;
			return false;
		}
	}
	else if(input.at(0) >= 'A' && input.at(0) <= 'Z')
	{
		if (input.length() > 1 && input.at(1) == '\'')
		{
			if(input.at(2) == '+')
			{
				return run1(x, input.substr(0, 2)) || run1(x, input.substr(3));
			}
			else if(input.at(2) == '*') 
			{
				return run1(x, input.substr(0, 2)) && run1(x, input.substr(3));
			}
			else if(input.at(2) == '^')
			{
				return run1(x, input.substr(0, 2)) ^ run1(x, input.substr(3));
			}
			else if(input.at(2) >= 'A' && input.at(2) <= 'Z')
			{
				return !run1(x, input.substr(0, 1)) && run1(x, input.substr(2));
			}
		}
		else if(input.at(1) == '+')
		{
			return run1(x, input.substr(0, 1)) || run1(x, input.substr(2));
		}
		else if(input.at(1) == '*')
		{
			return run1(x, input.substr(0, 1)) && run1(x, input.substr(2));
		}
		else if(input.at(1) == '^')
		{
			return run1(x, input.substr(0, 1)) ^ run1(x, input.substr(2));
		}
		else if(input.at(1) >= 'A' && input.at(1) <= 'Z')
		{
			return run1(x, input.substr(0, 1)) && run1(x, input.substr(1));
		}
	}
	//cout << x/find('A');
	return false;
}


void runByTable(string input)
{
	cout << "\n";
	std::list<char>::iterator iitr = inputs.begin();

	while(iitr != inputs.end())
	{
		cout << *iitr;
		iitr++;
	}
	cout << "    F\n";
	for(int i = 0; i < pow(2, inputs.size()); i++)
	{
		int x = 0;
		for(int j = inputs.size(); j > 0; j--)
		{
			x=x*10;
			x=x+(int)(i/pow(2, j-1))%2;
			cout << (int)(i/pow(2, j-1))%2 ;
		}
		//cout << x;
		//cout << "X is: " << x << "\n";
		if(run1(x, input))
		{
			cout << "    1";
		}
		else
		{
			cout << "    0";
		}
		cout << "\n";
	}
	
}





bool contains(std::list<char> list, char C)
{
	std::list<char>::iterator litr = list.begin();
	while(litr != list.end())
	{
		if(*litr == C)
		{
			return true;
		}
		litr++;
	}
	return false;
}

bool fq(string input)
{
	string::iterator sitr = input.begin();

	while(sitr != input.end())
	{
		if(*sitr > 'A'-1 && *sitr < 'Z'+1)
		{
			if(!contains(inputs, *sitr))
			{
				inputs.push_back(*sitr);
			}
		}
		sitr++;
	}
	
	/*	cout << "Using inputs:";
	std::list<char>::iterator litr = inputs.begin();
	while(litr != inputs.end())
	{
		cout << *litr << " ";
		litr++;
	}
	cout << "\n";*/

	/*if(run1(011, input))
	{
		cout << "TRUE" << endl;
	}
	else
	{
		cout << "FALSE" << endl;
	}*/
	runByTable(input);

}

int main()
{
	string eq = "";
	std::getline(std::cin, eq);
	
	eq.erase(std::remove(eq.begin(),eq.end(),' '),eq.end());

	//cout << "Working with the input:\n" << eq << endl;

	fq(eq);
}

