#ifndef GIFT_LUXURY_H
#define GIFT_LUXURY_H
#include "Gift.h"
#include <string>

namespace data {
	
	class Gift_Luxury: public Gift {
		public:
			
			Gift_Luxury(std::string, int, int, int, int, int);
	};
}

#endif

