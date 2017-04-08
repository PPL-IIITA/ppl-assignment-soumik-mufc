#ifndef MISER_H_
#define MISER_H_
#include "Boy.h"
#include <string>

namespace data
{
	class Miser: public Boy
	{
	public:
		Miser(std::string , int, int, int, int, int);
	};
}
#endif