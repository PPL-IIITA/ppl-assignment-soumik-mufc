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
				data::Choosy c(name, attract, intelli, budget, preference, type);
				g.push_back(c);
				break;
			}
			case 2:
			{
				data::Normal n(name, attract, intelli, budget, preference, type);
				g.push_back(n);
				break;
			}
			case 3:
			{
				data::Desperate d(name, attract, intelli, budget, preference, type);
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
				data::Miser m(name, attract, intelli, budget, min_attr_req, type);
				b.push_back(m);
				break;
			}
			case 2:
			{
				data::Generous g1(name, attract, intelli, budget, min_attr_req, type);
				b.push_back(g1);
				break;
			}
			case 3:
			{
				data::Geeky g2(name, attract, intelli, budget, min_attr_req, type);
				b.push_back(g2);
				break;
			}
			default:
				exit(0);
		}
	}
	ifs.close();
}

void utility::store_couples(std::vector <data::Couple> &couples)
{
	std::ofstream ofs1, ofs2;
	ofs1.open("../log_files/Couples_log.txt", std::ios::out); //* TimeStamp : Boy : Girl
	ofs2.open("../log_files/Couple_data.txt", std::ios::out); 
	//* b_name, g_name, b_attr, g_attr, b_intel, g_intel, b_budget, g_budget, b_type, g_type


	for(auto it = couples.begin(); it != couples.end(); it++)
	{
		time_t now = time(0);
		char * date = ctime(&now);
		//std::cout << it->boy.get_name() << " " << it->girl.get_name() << "\n";
		ofs1 << date << " " << it->boy.get_name() << " " << it->girl.get_name() << "\n";
		
		ofs2 << it->boy.get_name() << " " << it->girl.get_name() << " " << it->boy.get_attractiveness() << " " << it->girl.get_attractiveness() << " " << it->boy.get_intelligence() << " " << it->girl.get_intelligence() << " " << it->boy.get_budget() << " " << it->girl.get_budget() << " " << it->boy.get_type() << " " << it->girl.get_type() << "\n" ;

	}
	
	ofs1.close();
	ofs2.close();
}

int utility::stoint(const char *str)
{
	int num = 0;
	for(int i = 0; str[i] != '\0'; i++)
	{
		num = num * 10 + (str[i] - '0');
	}
	return num;
}

void utility::modified_store_couples(std::vector <data::Couple> &couples)
{
	std::ofstream ofs1, ofs2;
	ofs1.open("../log_files/modified_Couples_log.txt", std::ios::out); //* TimeStamp : Boy : Girl
	ofs2.open("../log_files/modified_Couple_data.txt", std::ios::out); 
	//* b_name, g_name, b_attr, g_attr, b_intel, g_intel, b_budget, g_budget, b_type, g_type


	for(auto it = couples.begin(); it != couples.end(); it++)
	{
		time_t now = time(0);
		char * date = ctime(&now);
		//std::cout << it->boy.get_name() << " " << it->girl.get_name() << "\n";
		ofs1 << date << " " << it->boy.get_name() << " " << it->girl.get_name() << "\n";
		
		ofs2 << it->boy.get_name() << " " << it->girl.get_name() << " " << it->boy.get_attractiveness() << " " << it->girl.get_attractiveness() << " " << it->boy.get_intelligence() << " " << it->girl.get_intelligence() << " " << it->boy.get_budget() << " " << it->girl.get_budget() << " " << it->boy.get_type() << " " << it->girl.get_type() << "\n" ;

	}
	
	ofs1.close();
	ofs2.close();
}
