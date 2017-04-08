/*
type of boy = {1=Miser, 2=Generous, 3=Geek}
type of girl = {1=Choosy, 2=Normal, 3=desperate}
prefernce type of girl = {1=attraciveness, 2=rich, 3=intelligent}
*/
//* Inserting datas in girls and boys csv files.
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ctime>
int main()
{
	std::ofstream ofs;
	srand(time(NULL));
	//* Inserting Boys data.
	ofs.open("../data_files/Boys.csv", std::ios::trunc);
	int i;
	for(i = 1; i < 100; i++)
	{
		std::string s = std::string("b") + std::to_string(i);
		int attr = rand() % 101 + 1;
		int intel = rand() % 101 + 1;
		int budget = rand() % 900 + 100;
		int attr_req = rand() % 101 + 1;
		int type = rand() % 3 + 1;
		ofs << s << " , " << attr << " , " << intel << " , " << budget << " , " << attr_req << " , " << type << "\n";
	}
	{
		std::string s = std::string("b") + std::to_string(i);
		int attr = rand() % 101 + 1;
		int intel = rand() % 101 + 1;
		int budget = rand() % 900 + 100;
		int attr_req = rand() % 101 + 1;
		int type = rand() % 3 + 1;
		ofs << s << " , " << attr << " , " << intel << " , " << budget << " , " << attr_req << " , " << type ;
	}
	ofs.close();
	//* Inserting girl data.
	ofs.open("../data_files/Girls.csv", std::ios::trunc);
	for(i = 1; i < 50; i++)
	{
		std::string s = std::string("g") + std::to_string(i);
		int attr = rand() % 101 + 1;
		int intel = rand() % 101 + 1;
		int budget = rand() % 900 + 100;
		int type = rand() % 3 + 1;
		int preference = rand() % 3 + 1;
		ofs << s << " , " << attr << " , " << intel << " , " << budget << " , " << type << " , " << preference <<"\n";
	}
	{
		std::string s = std::string("g") + std::to_string(i);
		int attr = rand() % 101 + 1;
		int intel = rand() % 101 + 1;
		int budget = rand() % 900 + 100;
		int type = rand() % 3 + 1;
		int preference = rand() % 3 + 1;
		ofs << s << " , " << attr << " , " << intel << " , " << budget << " , " << type << " , " << preference ;
	}

	return 0;
}
