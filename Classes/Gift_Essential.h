#ifndef GIFT_ESSENTIAL_H
#define GIFT_ESSENTIAL_H
#include "Gift.h"
#include <string>

namespace data {
	
	class Gift_Essential: public Gift {
		public:
			
			Gift_Essential(std::string, int, int, int, int, int);
	};
}

#endif

