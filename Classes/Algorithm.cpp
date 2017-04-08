#include "Algorithm.h"

void algorithm::make_couples(std::vector <data::Boy> &b, std::vector<data::Girl> &g, std::vector <data::Couple> &couples)
{
	
	int count = 0;
	for(auto girl_it = g.begin(); girl_it != g.end(); girl_it++)
	{
		int max_budget = 0;
		int max_attract = 0;
		int max_intel = 0;
		std::vector<data::Boy>::iterator m = b.begin();
		for(auto it = b.begin(); it != b.end(); it++)
		{
			if(it->get_commit_status() == false && it->get_budget() >= girl_it->get_budget() && girl_it->get_attractiveness() >= it->get_min_attr_req())
			{
				if(girl_it->get_preference() == 1 && max_attract < it->get_attractiveness())
				{
					m = it;
					max_attract = it->get_attractiveness();
				}
				else if(girl_it->get_preference() == 2 && max_budget < it->get_budget())
				{
					m = it;
					max_budget = it->get_budget();
				}
				else if(girl_it->get_preference() == 3 && max_intel < it->get_intelligence())
				{
					m = it;
					max_intel = it->get_intelligence();
				}
			}
		}
		if(m != b.begin())
		{
			m->set_commit_status(true);
			girl_it->set_commit_status(true);
			data::Couple c(*m, *girl_it);
			couples.push_back(c);
		}
		else if(count == 0)
		{
			m->set_commit_status(true);
			girl_it->set_commit_status(true);
			data::Couple c(*m, *girl_it);
			couples.push_back(c);
			count++;
		}
	}
}