#include "../Classes/Boy.h"
#include "../Classes/Girl.h"
#include "../Classes/Utility.h"
#include "../Classes/Algorithm.h"
#include <iostream>
#include <algorithm>
//* Comparator function for sorting by happiness.
bool happy_cmp(const data::Couple &c1, const data::Couple &c2) { return c1.get_happiness() > c2.get_happiness();}
//* Comparator function for sorting by compatibility.
bool compat_cmp(const data::Couple &c1, const data::Couple &c2) { return c1.get_compatibility() < c2.get_compatibility();}
int main(int argc, char const *argv[])
{
	std::vector <data::Girl> g;
	std::vector <data::Boy> b;
	std::vector <data::Couple> couples;
	utility::read_girl_data(g);
	utility::read_boy_data(b);
	
	algorithm::make_couples(b, g, couples);

	utility::store_couples(couples);

	algorithm::distribute_gifts(couples);

	int k = utility::stoint(argv[1]);

	sort(couples.begin(), couples.end(), happy_cmp);
	if(k > couples.size())
	{
		std::cout << "k exceeds no of couples\n\n";
		k = couples.size();
	}
	//* Printing k happiest couples.
	std::cout << k <<" most happiest Couples (happiness):\n\n";
	int count = 0;
	for(auto &it : couples)
	{
		if(k == count)
			break;
		std::cout << it.boy.get_name() << " " << it.girl.get_name() << " (" << it.get_happiness() <<")" << "\n";
		count++;
	}
	std::cout << "\n\n" << k <<" most compatible Couples (compatibility):\n";
	sort(couples.begin(), couples.end(), compat_cmp);
	count = 0;
	//*Printing k most compatible couples.
	for(auto &it : couples)
	{
		if(k == count)
			break;
		std::cout << it.boy.get_name() << " " << it.girl.get_name() << " (" << it.get_compatibility() <<")" << "\n";
		count++;	}
	return 0;
}
