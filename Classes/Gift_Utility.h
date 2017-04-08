#ifndef GIFT_UTILITY_H
#define GIFT_UTILITY_H
#include "Gift.h"
#include <string>

namespace data {
	
	class Gift_Utility: public Gift {
		public:
			
			Gift_Utility(std::string, int, int, int, int, int);
	};
}

#endif