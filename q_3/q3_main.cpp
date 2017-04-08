#include "../Classes/Boy.h"
#include "../Classes/Girl.h"
#include "../Classes/Utility.h"
#include "../Classes/Algorithm.h"
#include <typeinfo>
#include <iostream>
int main()
{
	std::vector <data::Girl> g;
	std::vector <data::Boy> b;
	std::vector <data::Couple> couples;
	utility::read_girl_data(g);
	utility::read_boy_data(b);
	/*for(auto &it : g)
		std::cout << typeid(it).name() << std::endl;
*/
	algorithm::make_couples(b, g, couples);

	for(auto &it : couples)
		std::cout << it.boy.get_name() << " " << it.girl.get_name() << std::endl;

	return 0;
}