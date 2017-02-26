
#ifndef HELPER_COUPLE_H_
#define HELPER_COUPLE_H_ 
#include "Gift.h"
#include "Couple.h"
#include <vector>
class Helper_couple
{
public:
	friend void give_gifts(std::vector <couple::Couple> &c);

};
void give_gifts(std::vector <couple::Couple> &c);

#endif