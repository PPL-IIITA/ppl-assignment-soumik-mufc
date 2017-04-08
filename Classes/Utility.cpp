#include "Utility.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

void utility::read_girl_data(std::vector <data::Girl> &g)
{
	std::ifstream ifs;
	ifs.open("../data_files/Girls.csv", std::ios::in);
	//*Reading data from Girls csv file.
	while(!ifs.eof())
	{
		std::string name;
		std::string ignore;
		int attract;
		int intelli;
		int budget;
		//int min_attr_req;
		int type;
		int preference;
		ifs >> name >> ignore >> attract >> ignore >> intelli >> ignore >> budget >>  ignore >>  type >> ignore >> preference;
		switch(type)
		{
			case 1:
			{
				data::Choosy c(name, attract, intelli, budget, preference);
				g.push_back(c);
				break;
			}
			case 2:
			{
				data::Normal n(name, attract, intelli, budget, preference);
				g.push_back(n);
				break;
			}
			case 3:
			{
				data::Desperate d(name, attract, intelli, budget, preference);
				g.push_back(d);
				break;
			}
			default:
				exit(0);
		}
	}
	ifs.close();

}

void utility::read_boy_data(std::vector <data::Boy> &b)
{
	std::ifstream ifs;
	//*Reading data from Boys csv file.
	ifs.open("../data_files/Boys.csv", std::ios::in);
	while(!ifs.eof())
	{
		std::string name;
		std::string ignore;
		int attract;
		int intelli;
		int budget;
		int min_attr_req;
		int type;
		ifs >> name >> ignore >> attract >> ignore >> intelli >> ignore >> budget >>  ignore >> min_attr_req >> ignore >> type;
		switch(type)
		{
			case 1:
			{
				data::Miser m(name, attract, intelli, budget, min_attr_req);
				b.push_back(m);
				break;
			}
			case 2:
			{
				data::Generous g1(name, attract, intelli, budget, min_attr_req);
				b.push_back(g1);
				break;
			}
			case 3:
			{
				data::Geeky g2(name, attract, intelli, budget, min_attr_req);
				b.push_back(g2);
				break;
			}
			default:
				exit(0);
		}
	}
	ifs.close();
}