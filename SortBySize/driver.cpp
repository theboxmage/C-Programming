#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <stdlib.h>     /* atof */

using namespace std;


struct item{
    int teir;
	double value;
	string name;
	bool operator< (item &i1)
	{
		if(i1.teir==teir)
		{
			return value > i1.value;
		}
		else
		{
			return teir > i1.teir;
		}
	}

};

void setTeir(char hold, item & h)
{
	if(hold=='K')
	{
		h.teir=1;
	}
	else if(hold=='M')
	{
		h.teir=2;
	}
	else if(hold=='G')
	{
		h.teir=3;
	}
	else
	{
		h.teir=0;
	}
}

bool mycompare ( item &i1, item &i2)
{
	return i1.teir < i2.teir;
}



int main()
{
	list<item> items;
	list<item>::iterator itr;
	string line;
	ifstream fs;
	fs.open("/tmp/hold");
	while (!fs.eof())
    {
		getline(fs, line);
		int find = line.find("	");
		string line1 = line.substr(0, find-1);
		char line2 = line.c_str()[find-1];
		item hold;
		hold.value = atof(line1.c_str());
		hold.name = line;
		setTeir(line2, hold);
		items.push_back(hold);
    }
	items.sort();
	itr=items.begin();
	while(itr!=items.end())
	{
		if(itr->name!="")
		{
			cout << itr->name<< endl;	
		}
		itr++;
	}

}
