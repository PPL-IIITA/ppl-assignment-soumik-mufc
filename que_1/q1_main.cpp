#include <string>
#include <iostream>
#include <vector>
#include "Helper.h"
//* Main Driver Program for question1 .
int main()
{
	//*Vector of of objects of different girls and boys.
	std::vector <miser::Miser> vb1;
	std::vector <generous::Generous> vb2;
	std::vector <geeky::Geeky> vb3;
	std::vector <choosy::Choosy> vg1;
	std::vector <normal::Normal> vg2;
	std::vector <desperate::Desperate> vg3;
	std::vector <std::pair<std::string, std::string>> couples;
	//*Scanning data from files and storing in vectors.
	scan_data(vb1, vb2, vb3, vg1, vg2, vg3);
	//*Making couples.
	make_couple(vb1, vb2, vb3, vg1, vg2, vg3, couples);
	//*Store the couples in files.
	store_couples(couples);
	return 0;
}