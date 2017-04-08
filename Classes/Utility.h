#ifndef UTILITY_H_
#define UTILITY_H_
#include <vector>
#include "Boy.h"
#include "Girl.h"
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

}


#endif