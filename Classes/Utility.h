#ifndef UTILITY_H_
#define UTILITY_H_
#include <vector>
#include "Boy.h"
#include "Girl.h"
#include "Couple.h"
#include "Boy_Geeky.h"
#include "Boy_Generous.h"
#include "Boy_Miser.h"
#include "Girl_Choosy.h"
#include "Girl_Desperate.h"
#include "Girl_Normal.h"

namespace utility
{
	void read_girl_data(std::vector <data::Girl> &g);
	void read_boy_data(std::vector <data::Boy> &b);
	void store_couples(std::vector <data::Couple> &couples);
	int stoint(const char *str);
	void modified_store_couples(std::vector <data::Couple> &couples);
	void read_list_of_boys(std::vector <std::string> &b_input);
	void read_couples(std::vector <data::Couple> &couples, std::vector <std::pair <std::string , std::string> > &cp);
}


#endif