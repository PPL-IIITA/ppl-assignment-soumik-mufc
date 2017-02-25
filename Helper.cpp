#include "Helper.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
/*

There is some bug which still needs to be looked at.
*/
void scan_data(std::vector<miser::Miser>& vb1, std::vector<generous::Generous>& vb2, std::vector<geeky::Geeky>& vb3, std::vector<choosy::Choosy>& vg1, std::vector<normal::Normal>& vg2, std::vector<desperate::Desperate>& vg3)
{
	std::ifstream ifs;

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

// Tester display function.
void display(const std::vector<miser::Miser> &vb1, const std::vector<generous::Generous> &vb2, const std::vector<geeky::Geeky> &vb3, const std::vector<choosy::Choosy> &vg1, const std::vector<normal::Normal> &vg2,const std::vector<desperate::Desperate> &vg3)

{
	for(auto it = vg1.begin(); it != vg1.end(); it++)
	{
		std::cout << it->getname() << " " << it->get_attractiveness() << " " << it->get_intelligence() << " " << it->get_budget() << " " << it->get_preference() << " " << it->get_commit_status() << std::endl;
	}
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
		if(type == 1)
		{
			std::vector <choosy::Choosy>::iterator c;
			for(c = vg1.begin(); c != vg1.end(); c++)
			{
				if(c->getname() == name)
					 break;
			}

			if(preference == 1)
			{
				std::vector<miser::Miser>::iterator m = vb1.begin();
				std::vector<generous::Generous>::iterator g1 = vb2.begin();
				std::vector<geeky::Geeky>::iterator g2 = vb3.begin();
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						m = it;
						break;
					}
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g1 = it;
						break;
					}
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g2 = it;
						break;
					}
				}
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_attractiveness() > m->get_attractiveness() && it->get_commit_status() == false && it->get_budget() >= budget)
						m = it;
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_attractiveness() > m->get_attractiveness() && it->get_commit_status() == false && it->get_budget() >= budget)
						g1 = it;
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_attractiveness() > m->get_attractiveness() && it->get_commit_status() == false && it->get_budget() >= budget)
						g2 = it;
				}
				int max = maximum( m->get_attractiveness(), g1->get_attractiveness(), g2->get_attractiveness());
				if(max == m->get_attractiveness() && m->get_budget() >= budget && m->get_commit_status() == false)
				{
					m->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(m->getname(), c->getname()));
				}
				if(max == g1->get_attractiveness() && g1->get_budget() >= budget && g1->get_commit_status() == false)
				{
					g1->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g1->getname(), c->getname()));
				}
				if(max == g2->get_attractiveness() && g2->get_budget() >= budget && g2->get_commit_status() == false)
				{
					g2->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g2->getname(), c->getname()));
				}


			}
			else if(preference == 2)
			{
				std::vector<miser::Miser>::iterator m = vb1.begin();
				std::vector<generous::Generous>::iterator g1 = vb2.begin();
				std::vector<geeky::Geeky>::iterator g2 = vb3.begin();
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						m = it;
						break;
					}
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g1 = it;
						break;
					}
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g2 = it;
						break;
					}
				}
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_budget() > m->get_budget() && it->get_commit_status() == false && it->get_budget() >= budget)
						m = it;
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_budget() > m->get_budget() && it->get_commit_status() == false && it->get_budget() >= budget)
						g1 = it;
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_budget() > m->get_budget() && it->get_commit_status() == false && it->get_budget() >= budget)
						g2 = it;
				}
				int max = maximum( m->get_budget(), g1->get_budget(), g2->get_budget());
				if(max == m->get_budget() && m->get_budget() >= budget && m->get_commit_status() == false)
				{
					m->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(m->getname(), c->getname()));
				}
				if(max == g1->get_budget() && g1->get_budget() >= budget && g1->get_commit_status() == false)
				{
					g1->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g1->getname(), c->getname()));
				}
				if(max == g2->get_budget() && g2->get_budget() >= budget && g2->get_commit_status() == false)
				{
					g2->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g2->getname(), c->getname()));
				}
			}
			else if(preference == 3)
			{
				std::vector<miser::Miser>::iterator m = vb1.begin();
				std::vector<generous::Generous>::iterator g1 = vb2.begin();
				std::vector<geeky::Geeky>::iterator g2 = vb3.begin();
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						m = it;
						break;
					}
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g1 = it;
						break;
					}
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g2 = it;
						break;
					}
				}
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_intelligence() > m->get_intelligence() && it->get_commit_status() == false && it->get_budget() >= budget)
						m = it;
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_intelligence() > m->get_intelligence() && it->get_commit_status() == false && it->get_budget() >= budget)
						g1 = it;
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_intelligence() > m->get_intelligence() && it->get_commit_status() == false && it->get_budget() >= budget)
						g2 = it;
				}
				int max = maximum( m->get_intelligence(), g1->get_intelligence(), g2->get_intelligence());
				if(max == m->get_intelligence() && m->get_budget() >= budget && m->get_commit_status() == false)
				{
					m->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(m->getname(), c->getname()));
				}
				if(max == g1->get_intelligence() && g1->get_budget() >= budget && g1->get_commit_status() == false)
				{
					g1->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g1->getname(), c->getname()));
				}
				if(max == g2->get_intelligence() && g2->get_budget() >= budget && g2->get_commit_status() == false)
				{
					g2->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g2->getname(), c->getname()));
				}
			}
		}
		else if(type == 2)
		{
			std::vector<normal::Normal>::iterator c;
			for(c = vg2.begin(); c != vg2.end(); c++)
			{
				if(c->getname() == name)
					 break;
			}

			if(preference == 1)
			{
				std::vector<miser::Miser>::iterator m = vb1.begin();
				std::vector<generous::Generous>::iterator g1 = vb2.begin();
				std::vector<geeky::Geeky>::iterator g2 = vb3.begin();
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						m = it;
						break;
					}
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g1 = it;
						break;
					}
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g2 = it;
						break;
					}
				}
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_attractiveness() > m->get_attractiveness() && it->get_commit_status() == false && it->get_budget() >= budget)
						m = it;
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_attractiveness() > m->get_attractiveness() && it->get_commit_status() == false && it->get_budget() >= budget)
						g1 = it;
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_attractiveness() > m->get_attractiveness() && it->get_commit_status() == false && it->get_budget() >= budget)
						g2 = it;
				}
				int max = maximum( m->get_attractiveness(), g1->get_attractiveness(), g2->get_attractiveness());
				if(max == m->get_attractiveness() && m->get_budget() >= budget && m->get_commit_status() == false)
				{
					m->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(m->getname(), c->getname()));
				}
				if(max == g1->get_attractiveness() && g1->get_budget() >= budget && g1->get_commit_status() == false)
				{
					g1->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g1->getname(), c->getname()));
				}
				if(max == g2->get_attractiveness() && g2->get_budget() >= budget && g2->get_commit_status() == false)
				{
					g2->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g2->getname(), c->getname()));
				}


			}
			else if(preference == 2)
			{
				std::vector<miser::Miser>::iterator m = vb1.begin();
				std::vector<generous::Generous>::iterator g1 = vb2.begin();
				std::vector<geeky::Geeky>::iterator g2 = vb3.begin();
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						m = it;
						break;
					}
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g1 = it;
						break;
					}
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g2 = it;
						break;
					}
				}
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_budget() > m->get_budget() && it->get_commit_status() == false && it->get_budget() >= budget)
						m = it;
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_budget() > m->get_budget() && it->get_commit_status() == false && it->get_budget() >= budget)
						g1 = it;
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_budget() > m->get_budget() && it->get_commit_status() == false && it->get_budget() >= budget)
						g2 = it;
				}
				int max = maximum( m->get_budget(), g1->get_budget(), g2->get_budget());
				if(max == m->get_budget() && m->get_budget() >= budget && m->get_commit_status() == false)
				{
					m->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(m->getname(), c->getname()));
				}
				if(max == g1->get_budget() && g1->get_budget() >= budget && g1->get_commit_status() == false)
				{
					g1->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g1->getname(), c->getname()));
				}
				if(max == g2->get_budget() && g2->get_budget() >= budget && g2->get_commit_status() == false)
				{
					g2->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g2->getname(), c->getname()));
				}
			}
			else if(preference == 3)
			{
				std::vector<miser::Miser>::iterator m = vb1.begin();
				std::vector<generous::Generous>::iterator g1 = vb2.begin();
				std::vector<geeky::Geeky>::iterator g2 = vb3.begin();
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						m = it;
						break;
					}
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g1 = it;
						break;
					}
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g2 = it;
						break;
					}
				}
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_intelligence() > m->get_intelligence() && it->get_commit_status() == false && it->get_budget() >= budget)
						m = it;
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_intelligence() > m->get_intelligence() && it->get_commit_status() == false && it->get_budget() >= budget)
						g1 = it;
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_intelligence() > m->get_intelligence() && it->get_commit_status() == false && it->get_budget() >= budget)
						g2 = it;
				}
				int max = maximum( m->get_intelligence(), g1->get_intelligence(), g2->get_intelligence());
				if(max == m->get_intelligence() && m->get_budget() >= budget && m->get_commit_status() == false)
				{
					m->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(m->getname(), c->getname()));
				}
				if(max == g1->get_intelligence() && g1->get_budget() >= budget && g1->get_commit_status() == false)
				{
					g1->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g1->getname(), c->getname()));
				}
				if(max == g2->get_intelligence() && g2->get_budget() >= budget && g2->get_commit_status() == false)
				{
					g2->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g2->getname(), c->getname()));
				}
			}
		}
		else if(type == 3)
		{
			std::vector<desperate::Desperate>::iterator c;

			for(c = vg3.begin(); c != vg3.end(); c++)
			{
				if(c->getname() == name)
					 break;
			}

			if(preference == 1)
			{
				std::vector<miser::Miser>::iterator m = vb1.begin();
				std::vector<generous::Generous>::iterator g1 = vb2.begin();
				std::vector<geeky::Geeky>::iterator g2 = vb3.begin();
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						m = it;
						break;
					}
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g1 = it;
						break;
					}
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g2 = it;
						break;
					}
				}
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_attractiveness() > m->get_attractiveness() && it->get_commit_status() == false && it->get_budget() >= budget)
						m = it;
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_attractiveness() > m->get_attractiveness() && it->get_commit_status() == false && it->get_budget() >= budget)
						g1 = it;
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_attractiveness() > m->get_attractiveness() && it->get_commit_status() == false && it->get_budget() >= budget)
						g2 = it;
				}
				int max = maximum( m->get_attractiveness(), g1->get_attractiveness(), g2->get_attractiveness());
				if(max == m->get_attractiveness() && m->get_budget() >= budget && m->get_commit_status() == false)
				{
					m->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(m->getname(), c->getname()));
				}
				if(max == g1->get_attractiveness() && g1->get_budget() >= budget && g1->get_commit_status() == false)
				{
					g1->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g1->getname(), c->getname()));
				}
				if(max == g2->get_attractiveness() && g2->get_budget() >= budget && g2->get_commit_status() == false)
				{
					g2->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g2->getname(), c->getname()));
				}
				

			}
			else if(preference == 2)
			{
				std::vector<miser::Miser>::iterator m = vb1.begin();
				std::vector<generous::Generous>::iterator g1 = vb2.begin();
				std::vector<geeky::Geeky>::iterator g2 = vb3.begin();
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						m = it;
						break;
					}
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g1 = it;
						break;
					}
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g2 = it;
						break;
					}
				}
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_budget() > m->get_budget() && it->get_commit_status() == false && it->get_budget() >= budget)
						m = it;
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_budget() > m->get_budget() && it->get_commit_status() == false && it->get_budget() >= budget)
						g1 = it;
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_budget() > m->get_budget() && it->get_commit_status() == false && it->get_budget() >= budget)
						g2 = it;
				}
				int max = maximum( m->get_budget(), g1->get_budget(), g2->get_budget());
				if(max == m->get_budget() && m->get_budget() >= budget && m->get_commit_status() == false)
				{
					m->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(m->getname(), c->getname()));
				}
				if(max == g1->get_budget() && g1->get_budget() >= budget && g1->get_commit_status() == false)
				{
					g1->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g1->getname(), c->getname()));
				}
				if(max == g2->get_budget() && g2->get_budget() >= budget && g2->get_commit_status() == false)
				{
					g2->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g2->getname(), c->getname()));
				}
			}
			else if(preference == 3)
			{
				std::vector<miser::Miser>::iterator m = vb1.begin();
				std::vector<generous::Generous>::iterator g1 = vb2.begin();
				std::vector<geeky::Geeky>::iterator g2 = vb3.begin();
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						m = it;
						break;
					}
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g1 = it;
						break;
					}
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_commit_status() == false && it->get_budget() >= budget)
					{
						g2 = it;
						break;
					}
				}
				for(auto it = vb1.begin(); it != vb1.end(); it++)
				{
					if(it->get_intelligence() > m->get_intelligence() && it->get_commit_status() == false && it->get_budget() >= budget)
						m = it;
				}
				for(auto it = vb2.begin(); it != vb2.end(); it++)
				{
					if(it->get_intelligence() > m->get_intelligence() && it->get_commit_status() == false && it->get_budget() >= budget)
						g1 = it;
				}
				for(auto it = vb3.begin(); it != vb3.end(); it++)
				{
					if(it->get_intelligence() > m->get_intelligence() && it->get_commit_status() == false && it->get_budget() >= budget)
						g2 = it;
				}
				int max = maximum( m->get_intelligence(), g1->get_intelligence(), g2->get_intelligence());
				if(max == m->get_intelligence() && m->get_budget() >= budget && m->get_commit_status() == false)
				{

					m->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(m->getname(), c->getname()));
				}
				if(max == g1->get_intelligence() && g1->get_budget() >= budget && g1->get_commit_status() == false)
				{
					g1->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g1->getname(), c->getname()));
				}
				if(max == g2->get_intelligence() && g2->get_budget() >= budget && g2->get_commit_status() == false)
				{
					g2->set_commit_status(true);
					c->set_commit_status(true);
					couples.push_back(make_pair(g2->getname(), c->getname()));
				}
			}	
		}
	}
}

void store_couples(std::vector <std::pair<std::string, std::string>> &couples)
{
	std::ofstream ofs;
	ofs.open("Couples_log.txt", std::ios::out);
	for(auto it = couples.begin(); it != couples.end(); it++)
	{
		ofs << it->first << " " << it->second << "\n";
	}
	ofs.close();
}

