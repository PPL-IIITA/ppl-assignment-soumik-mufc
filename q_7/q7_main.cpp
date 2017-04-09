#include "../Classes/Boy.h"
#include "../Classes/Girl.h"
#include "../Classes/Utility.h"
#include "../Classes/Algorithm.h"
#include <iostream>
#include <algorithm>


int main(int argc, char const *argv[])
{
	//* 1 command-line-arguement (t): To break up couples from 1 to t days whose happiness is less than t;
	//* 1 - 1st method of finding girlfriend : vector method
	//* 2 - 2nd method of finding girlfriend : binary search
	//* 3 - 3rd method of finding girlfriend : 
	int choice;
	if(argc == 1)
		choice = 1; //* default choice is 1.
	else 
		choice = utility::stoint(argv[1]);
	std::vector <data::Girl> g;
	std::vector <data::Boy> b;
	std::vector <data::Couple> couples;
	utility::read_girl_data(g);
	utility::read_boy_data(b);
	
	algorithm::make_couples(b, g, couples);

	std::vector <std::string> b_input;
	std::vector <std::pair <std::string , std::string> > cp; // vector of <boy, girl>
	utility::read_list_of_boys(b_input);
	utility::read_couples(couples, cp);

	algorithm::find_girlfriend(cp, b_input, choice);

		
	return 0;
}