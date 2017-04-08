#ifndef GEEKY_H_
#define GEEKY_H_
#include "Boy.h"
#include <string>

namespace data
{
	class Geeky: public Boy
	{
	public:
		Geeky(std::string , int, int, int, int, int);
	};
}

#endif