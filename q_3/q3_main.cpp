#include "../Classes/Boy.h"
#include "../Classes/Girl.h"
#include "../Classes/Utility.h"
#include <iostream>
int main()
{
	std::vector <data::Girl> g;
	std::vector <data::Boy> b;
	utility::read_girl_data(g);
	for(auto &it : g)
		std::cout << it.get_name() << std::endl;
	return 0;
}