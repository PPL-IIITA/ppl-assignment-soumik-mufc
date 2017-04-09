#include "../Classes/Boy.h"
#include "../Classes/Girl.h"
#include "../Classes/Utility.h"
#include "../Classes/Algorithm.h"
#include <iostream>
#include <algorithm>


int main(int argc, char const *argv[])
{
	//* 1 command-line-arguement (t): To break up couples from 1 to t days whose happiness is less than t;
	int t = utility::stoint(argv[1]);
	std::vector <data::Girl> g;
	std::vector <data::Boy> b;
	std::vector <data::Couple> couples;
	utility::read_girl_data(g);
	utility::read_boy_data(b);
	
	algorithm::make_couples(b, g, couples);

	algorithm::distribute_gifts(couples);

	algorithm::modified_break_up(couples, b, g, t);
	
	utility::store_couples(couples);
	return 0;
}