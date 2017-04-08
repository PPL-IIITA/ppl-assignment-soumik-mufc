#include "../Classes/Boy.h"
#include "../Classes/Girl.h"
#include "../Classes/Utility.h"
#include "../Classes/Algorithm.h"
#include <iostream>
#include <algorithm>
//* Comparator function for sorting by happiness.
bool happy_cmp(const data::Couple &c1, const data::Couple &c2) { return c1.get_happiness() < c2.get_happiness();}

bool girl_name_cmp(const data::Couple &c1, const data::Couple &c2)
{
	return c1.girl.get_name() < c2.girl.get_name();
}

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

	//sort(couples.begin(), couples.end(), happy_cmp);

	algorithm::break_up(couples, b, g, k);

	sort(couples.begin(), couples.end(), girl_name_cmp);
	utility::modified_store_couples(couples);

	return 0;
}