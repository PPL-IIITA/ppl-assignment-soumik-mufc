#ifndef GENEROUS_H_
#define GENEROUS_H_
#include "Boy.h"
#include <string>

namespace data
{
	class Generous:public Boy
	{
	public:
		Generous(std::string , int, int, int, int);
	};
}

#endif