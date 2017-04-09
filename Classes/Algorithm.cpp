#include "Algorithm.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
bool gift_cmp(const data::Gift &g1, const data::Gift &g2)
{
    return g1.get_price() < g2.get_price();
}

bool girl_cmp_maint(const data::Girl &g1, const data::Girl &g2)
{
    return g1.get_budget() < g2.get_budget();
}
bool boy_cmp_attract(const data::Boy &b1, const data::Boy &b2)
{
    return b1.get_attractiveness() < b2.get_attractiveness();
}
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

void algorithm::distribute_gifts(std::vector <data::Couple> &c)
{
    std::vector<data::Gift> g;
    
	std::ifstream input;
    //*Gifts exchange between girls and boys.
    input.open("../data_files/Gifts.csv", std::ios::in);
    while(!input.eof()) {
        std::string name;
        std::string ign;
        int price;
        int value;
        int type;
        int data1;
        int data2;
        input >> name >> ign >> price >> ign >> value >> ign >> type >> ign >> data1 >> ign >> data2;
        data::Gift g1(name,price,value,type,data1,data2);
        g.push_back(g1);
    }
    /*for(auto &it : g)
    	std::cout << it.get_name() << std::endl;*/

    input.close();

    //*Sorting gifts by price.
    sort(g.begin(), g.end(), gift_cmp);
    std::ofstream ofs;
    ofs.open("../log_files/Gifts_log.txt");
    for(auto &cp : c)
    {
        int max = cp.girl.get_budget();
        int sum_price = 0;
        int sum_value = 0;
        int lux_price = 0;
        //ofs << cp.get_boy_name() << " " << cp.get_girl_name() << "\n";
        for(auto &gft : g)
        {
            time_t t = time(0);
            char * date = ctime(&t);
            if(sum_price > max)
                break;
            sum_price += gft.get_price();
            sum_value += gft.get_value();
            if(gft.get_type() == 2)
                lux_price += gft.get_price();
            //std::cout << date << cp.get_boy_name() << " " << cp.get_girl_name() << gft.get_name() << "\n";
            ofs << date << cp.boy.get_name() << " " << cp.girl.get_name() << " " <<  gft.get_name() << "\n";
        }
        //* Calculating happiness level of each member of a couple.
        if(cp.girl.get_type() == 1)
        {
            cp.girl.set_happiness(log(sum_price + lux_price - cp.girl.get_budget()));
        }
        else if(cp.girl.get_type() == 2)
        {
            cp.girl.set_happiness(sum_price + sum_value - cp.girl.get_budget());
        }
        else if(cp.girl.get_type() == 3)
        {
            cp.girl.set_happiness(pow(2.71828, sum_price - cp.girl.get_budget()));
        }
        if(cp.boy.get_type() == 1)
        {
            cp.boy.set_happiness(abs(sum_price - cp.boy.get_budget()));
        }
        else if(cp.boy.get_type() == 2)
        {
            cp.boy.set_happiness(cp.girl.get_happiness());
        }
        else if(cp.boy.get_type() == 3)
        {
            cp.boy.set_happiness(cp.girl.get_intelligence());
        }
        //* Set happiness level of couple.
        cp.set_happiness();
        //*Set compatibility of couple.
        cp.set_compatibility();

    }
    ofs.close();
}

void algorithm::break_up(std::vector <data::Couple> &c, std::vector <data::Boy> &b, std::vector<data::Girl> &g, int k)
{
    std::map <std::string, std::string> broken_couples;  //* broken_couples[girl_name] = boy_name

    for(int i = 0; i < k; i++)
        broken_couples[c[i].girl.get_name()] = c[i].boy.get_name();


    for(auto it1 = broken_couples.begin(); it1 != broken_couples.end(); it1++)
    {
        int index = 0;
        for(auto it2 = c.begin(); it2 != c.end(); it2++)
        {
            if(it2->boy.get_name() == it1->second)
                break;
            index++;
        }
        c.erase(c.begin() + index);
    }
    /*for(auto it = c.begin(); it != c.end(); it++)
    {
        std::cout << it->boy.get_name() << " " << it->girl.get_name() << std::endl;
    }*/

    for(auto it1 = broken_couples.begin(); it1 != broken_couples.end(); it1++)
    {
        for(auto it2 = b.begin(); it2 != b.end(); it2++)
        {
            if(it2->get_name() == it1->second)
            {
                it2->set_commit_status(false);
                break;
            }
        }
    }

    for(auto it1 = broken_couples.begin(); it1 != broken_couples.end(); it1++)
    {
        for(auto it2 = g.begin(); it2 != g.end(); it2++)
        {
            if(it2->get_name() == it1->first)
            {
                it2->set_commit_status(false);
                break;
            }
            
        }
    }

   /* int count = 0;
    for(auto it = b.begin(); it != b.end(); it++)
    {
        if(it->get_commit_status() == true)
            count++;
        std::cout << it->get_commit_status() << std::endl;
    }
    std::cout << count;*/
    /*for(auto it = broken_couples.begin(); it != broken_couples.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;*/



    int count = 0;
    for(auto girl_it = g.begin(); girl_it != g.end(); girl_it++)
    {
        int max_budget = 0;
        int max_attract = 0;
        int max_intel = 0;
        std::vector<data::Boy>::iterator m = b.begin();
        if(girl_it->get_commit_status() == false)
        {
        for(auto it = b.begin(); it != b.end(); it++)
        {
            if(it->get_commit_status() == false && it->get_budget() >= girl_it->get_budget() && girl_it->get_attractiveness() >= it->get_min_attr_req() && broken_couples[girl_it->get_name()] != it->get_name())
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
            data::Couple cp(*m, *girl_it);
            c.push_back(cp);
        }
        else if(count == 0)
        {
            m->set_commit_status(true);
            girl_it->set_commit_status(true);
            data::Couple cp(*m, *girl_it);
            c.push_back(cp);
            count++;
        }
        }
    }
}

void algorithm::modified_make_couples(std::vector <data::Boy> &b, std::vector<data::Girl> &g, std::vector <data::Couple> &couples)
{
    std::sort(g.begin(), g.end(), girl_cmp_maint);
    std::sort(b.begin(), b.end(), boy_cmp_attract);

    int count = 0;

    while(true)
    {
        bool flag = false;
        if(count % 2 == 0)
        {
            for(auto girl_it = g.begin(); girl_it != g.end(); girl_it++)
            {
                if(girl_it->get_commit_status() == true)
                    continue;
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
                if(m->get_commit_status() == false)
                {
                    m->set_commit_status(true);
                    girl_it->set_commit_status(true);
                    data::Couple c(*m, *girl_it);
                    couples.push_back(c);
                    flag = true;
                    break;
                }
            }
        }
        else
        {
            for(auto boy_it = b.begin(); boy_it != b.end(); boy_it++)
            {
                if(boy_it->get_commit_status() == true)
                    continue;
                int max_attract = 0;
                std::vector<data::Girl>::iterator m = g.begin();
                for(auto it = g.begin(); it != g.end(); it++)
                {
                    if(it->get_commit_status() == false && it->get_budget() <= boy_it->get_budget() && it->get_attractiveness() >= boy_it->get_min_attr_req())
                    {
                        if(it->get_attractiveness() > max_attract)
                        {
                            max_attract = it->get_attractiveness();
                            m = it;
                        }
                    }
                }
                if(m->get_commit_status() == false)
                {
                    m->set_commit_status(true);
                    boy_it->set_commit_status(true);
                    data::Couple c(*boy_it, *m);
                    couples.push_back(c);
                    flag = true;
                    break;
                }
            }
        }
        if(flag == false)
            break;
    }


}