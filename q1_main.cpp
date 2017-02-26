#include <string>
#include <iostream>
#include <vector>
#include "Helper.h"
int main()
{
	std::vector <miser::Miser> vb1;
	std::vector <generous::Generous> vb2;
	std::vector <geeky::Geeky> vb3;
	std::vector <choosy::Choosy> vg1;
	std::vector <normal::Normal> vg2;
	std::vector <desperate::Desperate> vg3;
	std::vector <std::pair<std::string, std::string>> couples;
	scan_data(vb1, vb2, vb3, vg1, vg2, vg3);
	make_couple(vb1, vb2, vb3, vg1, vg2, vg3, couples);
	store_couples(couples);
	return 0;
}