#ifndef DESPERATE_H_
#define DESPERATE_H_
#include "Girl.h"
#include <string>

namespace data
{
	class Desperate:public Girl
	{
	public:
		Desperate(std::string , int, int, int, int, int);
	};
}

#endif