#include "Algorithm.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cmath>
bool gift_cmp(const data::Gift &g1, const data::Gift &g2)
{
    return g1.get_price() < g2.get_price();
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

    /*
    input.open("../data_files/Couple_data.txt", std::ios::in);
    std::string name1;
    while(input >> name1) {
        std::string name2;
        int at1, at2;
        int in1, in2;
        int budget1, budget2;
        int type1, type2;
        input >> name2 >> at1 >> at2 >> in1 >> in2 >> budget1 >> budget2 >> type1 >> type2;
        couple::Couple c1(name1,name2,at1,at2,in1,in2, budget1, budget2, type1, type2);
        c.push_back(c1);
    }*/
    //*Sorting gifts by price.
    sort(g.begin(), g.end(), gift_cmp);
    std::ofstream ofs;
    ofs.open("Gifts_log.txt");
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