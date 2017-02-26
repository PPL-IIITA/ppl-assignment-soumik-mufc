#include "Helper_couple.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
bool gift_cmp(const gift::Gift &g1, const gift::Gift &g2)
{
    return g1.get_price() < g2.get_price();
}
void give_gifts(std::vector <couple::Couple> &c)
{
    std::vector<gift::Gift> g;
    
	std::ifstream input;
    
    input.open("Gifts.csv", std::ios::in);
    while(!input.eof()) {
        std::string name;
        std::string ign;
        int price;
        int value;
        int type;
        int data1;
        int data2;
        input >> name >> ign >> price >> ign >> value >> ign >> type >> ign >> data1 >> ign >> data2;
        gift::Gift g1(name,price,value,type,data1,data2);
        g.push_back(g1);
    }
    input.close();
    input.open("Couple_log_2.txt", std::ios::in);
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
    }
    //Sorting gifts by price
    sort(g.begin(), g.end(), gift_cmp);
    std::ofstream ofs;
    ofs.open("Gifts_log.txt");
    for(auto &cp : c)
    {
        int max = cp.get_girl_budget();
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
            ofs << date << cp.get_boy_name() << " " << cp.get_girl_name() << " " <<  gft.get_name() << "\n";
        }
        if(cp.get_girl_type() == 1)
        {
            cp.set_girl_happy(log(sum_price + lux_price - cp.get_girl_budget()));
        }
        else if(cp.get_girl_type() == 2)
        {
            cp.set_girl_happy(sum_price + sum_value - cp.get_girl_budget());
        }
        else if(cp.get_girl_type() == 3)
        {
            cp.set_girl_happy(pow(2.71828, sum_price - cp.get_girl_budget()));
        }
        if(cp.get_boy_type() == 1)
        {
            cp.set_boy_happy(abs(sum_price - cp.get_boy_budget()));
        }
        else if(cp.get_boy_type() == 2)
        {
            cp.set_boy_happy(cp.get_girl_happy());
        }
        else if(cp.get_boy_type() == 3)
        {
            cp.set_boy_happy(cp.get_girl_intel());
        }
        cp.set_happiness();
        cp.set_compatibility();

    }
    ofs.close();
}