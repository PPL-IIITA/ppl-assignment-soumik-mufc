#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "Girl.h"
#include "Boy.h"
#include "Couple.h"
#include "Gift.h"
#include <vector>


namespace algorithm
{
	void make_couples(std::vector <data::Boy> &b, std::vector <data::Girl> &g, std::vector <data::Couple> &couples);

	void distribute_gifts(std::vector <data::Couple> &c);

	void break_up(std::vector <data::Couple> &c, std::vector <data::Boy> &b, std::vector<data::Girl> &g, int k);
}

#endif