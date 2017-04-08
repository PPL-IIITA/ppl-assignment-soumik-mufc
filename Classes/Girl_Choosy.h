#ifndef CHOOSY_H_
#define CHOOSY_H_
#include "Girl.h"
#include <string>

namespace data
{
	class Choosy:public Girl
	{
	public:
		Choosy(std::string , int, int, int, int, int);
	};
}

#endif