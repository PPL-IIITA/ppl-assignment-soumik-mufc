#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ctime>

//*Generates random gifts to be stored in Gifts csv file.
/*
Gift types = {1=essential,2=luxury,3=utility}
*/
int main()
{
	std::ofstream ofs;
	srand(time(NULL));
	//* Inserting Gifts data.
	ofs.open("../data_files/Gifts.csv", std::ios::trunc);
	int i;
	for(i = 1; i < 1000; i++)
	{
		std::string s = std::string("gift") + std::to_string(i);
		int price = rand() % 100 + 1;
		int value = rand() % 10 + 1;
		int type = rand() % 3+ 1;
		int d1, d2;
		if(type == 1)
		{
			d1 = -1;
			d2 = -1;
		}
		else
		{
			d1 = rand() % 10 + 1;
			d2 = rand() % 10 + 1;
		}
		ofs << s << " , " << price << " , " << value << " , " << type << " , " << d1 << " , " << d2 << "\n";
	}
	std::string s = std::string("gift") + std::to_string(i);
	int price = rand() % 101 + 1;
	int value = rand() % 10 + 1;
	int type = rand() + 1;
	int d1, d2;
	if(type == 1)
	{
		d1 = -1;
		d2 = -1;
	}
	else
	{
		d1 = rand() % 10 + 1;
		d2 = rand() % 10 + 1;
	}
	ofs << s << " , " << price << " , " << value << " , " << type << " , " << d1 << " , " << d2 << "\n";
	return 0;
}
