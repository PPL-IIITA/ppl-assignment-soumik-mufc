#include "Helper.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <ctime>
/*

Bugs have benen removed.
*/
void scan_data(std::vector<miser::Miser>& vb1, std::vector<generous::Generous>& vb2, std::vector<geeky::Geeky>& vb3, std::vector<choosy::Choosy>& vg1, std::vector<normal::Normal>& vg2, std::vector<desperate::Desperate>& vg3)
{
	std::ifstream ifs;
	//*Reading data from Boys csv file.
	ifs.open("Boys.csv", std::ios::in);
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
				miser::Miser m(name, attract, intelli, budget, min_attr_req);
				vb1.push_back(m);
				break;
			}
			case 2:
			{
				generous::Generous g1(name, attract, intelli, budget, min_attr_req);
				vb2.push_back(g1);
				break;
			}
			case 3:
			{
				geeky::Geeky g2(name, attract, intelli, budget, min_attr_req);
				vb3.push_back(g2);
				break;
			}
			default:
				exit(0);
		}
	}
	ifs.close();
	ifs.open("Girls.csv", std::ios::in);
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
				choosy::Choosy c(name, attract, intelli, budget, preference);
				vg1.push_back(c);
				break;
			}
			case 2:
			{
				normal::Normal n(name, attract, intelli, budget, preference);
				vg2.push_back(n);
				break;
			}
			case 3:
			{
				desperate::Desperate d(name, attract, intelli, budget, preference);
				vg3.push_back(d);
				break;
			}
			default:
				exit(0);
		}
	}
	ifs.close();
}

int maximum( int a, int b, int c ) { return std::max( std::max(a,b), c ) ; }

void make_couple(std::vector<miser::Miser> &vb1, std::vector<generous::Generous> &vb2, std::vector<geeky::Geeky> &vb3, std::vector<choosy::Choosy> &vg1, std::vector<normal::Normal> &vg2, std::vector<desperate::Desperate> &vg3, std::vector <std::pair<std::string, std::string>> &couples)
{

	std::ifstream ifs;
	ifs.open("Girls.csv", std::ios::in);
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
		
		//* Allocating boys to every girl(as far as possible) as per the question.
		int max_budget = 0, max_attract = 0,max_intel = 0;

		std::vector<miser::Miser>::iterator m = vb1.begin();
		std::vector<generous::Generous>::iterator g1 = vb2.begin();
		std::vector<geeky::Geeky>::iterator g2 = vb3.begin();
		int chosen = 0;

		for(auto it = vb1.begin(); it != vb1.end(); it++)
		{
			if(it->get_commit_status() == false && it->get_budget() >= budget && attract >= it->get_min_attr_req())
			{
				if(preference == 1 && max_attract < it->get_attractiveness())
				{
					m = it;
					chosen = 1;
					max_attract = it->get_attractiveness();
				}
				else if(preference == 2 && max_budget < it->get_budget())
				{
					m = it;
					chosen = 1;
					max_budget = it->get_budget();
				}
				else if(preference == 3 && max_intel < it->get_intelligence())
				{
					m = it;
					chosen = 1;
					max_intel = it->get_intelligence();
				}
			}
		}
		for(auto it = vb2.begin(); it != vb2.end(); it++)
		{
			if(it->get_commit_status() == false && it->get_budget() >= budget && attract >= it->get_min_attr_req())
			{
				if(preference == 1 && max_attract < it->get_attractiveness())
				{
					g1 = it;
					chosen = 2;
					max_attract = it->get_attractiveness();
				}
				else if(preference == 2 && max_budget < it->get_budget())
				{
					g1 = it;
					chosen = 2;
					max_budget = it->get_budget();
				}
				else if(preference == 3 && max_intel < it->get_intelligence())
				{
					g1 = it;
					chosen = 2;
					max_intel = it->get_intelligence();
				}
			}
		}
		for(auto it = vb3.begin(); it != vb3.end(); it++)
		{
			if(it->get_commit_status() == false && it->get_budget() >= budget && attract >= it->get_min_attr_req())
			{
				if(preference == 1 && max_attract < it->get_attractiveness())
				{
					g2 = it;
					chosen = 3;
					max_attract = it->get_attractiveness();
				}
				else if(preference == 2 && max_budget < it->get_budget())
				{
					g2 = it;
					chosen = 3;
					max_budget = it->get_budget();
				}
				else if(preference == 3 && max_intel < it->get_intelligence())
				{
					g2 = it;
					chosen = 3;
					max_intel = it->get_intelligence();
				}
			}
		}
		
		if(chosen == 1)
		{
			m->set_commit_status(true);
			couples.push_back(make_pair(m->getname(), name));
		}
		else if(chosen == 2)
		{
			g1->set_commit_status(true);
			couples.push_back(make_pair(g1->getname(), name));
		}
		else if(chosen == 3)
		{
			g2->set_commit_status(true);
			couples.push_back(make_pair(g2->getname(), name));
		}
	}
}

void store_couples(std::vector <std::pair<std::string, std::string>> &couples)
{
	//*Store couples into Couples_log and couple_log_2 txt files.
	std::ofstream ofs1, ofs2;
	ofs1.open("Couples_log.txt", std::ios::out);
	ofs2.open("Couple_log_2.txt", std::ios::out);
	for(auto it = couples.begin(); it != couples.end(); it++)
	{
		time_t now = time(0);
		char * date = ctime(&now);
		std::cout << it->first << " " << it->second << "\n";
		ofs1 << date << " " << it->first << " " << it->second << "\n";
		std::ifstream ifs1, ifs2;
		ifs1.open("Boys.csv");
		ifs2.open("Girls.csv");
		std::string name1, name2;
		std::string ignore;
		int attract1, attract2;
		int intelli1, intelli2;
		int budget1, budget2;
		int min_attr_req1, preference2;
		int type1, type2;
		while(!ifs1.eof())
		{

			ifs1 >> name1 >> ignore >> attract1 >> ignore >> intelli1 >> ignore >> budget1 >>  ignore >> min_attr_req1 >> ignore >> type1;
			if(name1 == it->first)
				break;
		}
		while(!ifs2.eof())
		{
			ifs2 >> name2 >> ignore >> attract2 >> ignore >> intelli2 >> ignore >> budget2 >>  ignore >>  type2 >> ignore >> preference2;
			if(name2 == it->second)
				break;
		}
		ofs2 << name1 << " " << name2 << " " << attract1 << " " << attract2 << " " << intelli1 << " " << intelli2 << " " << budget1 << " " << budget2 << " " << type1 << " " << type2 << "\n" ;

	}
	ofs1.close();
	ofs2.close();
}