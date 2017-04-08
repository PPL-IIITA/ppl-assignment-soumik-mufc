#ifndef NORMAL_H_
#define NORMAL_H_
#include "Girl.h"
#include <string>

namespace data
{
	class Normal:public Girl
	{
	public:
		Normal(std::string , int, int, int, int);
	};
}

#endif