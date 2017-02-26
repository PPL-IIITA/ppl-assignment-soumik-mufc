#include "Helper_couple.h"
#include "Gift.h"
#include "Couple.h"
#include <iostream>
#include <algorithm>
bool happy_cmp(const couple::Couple &c1, const couple::Couple &c2) { return c1.get_happiness() > c2.get_happiness();}
bool compat_cmp(const couple::Couple &c1, const couple::Couple &c2) { return c1.get_compatibility() < c2.get_compatibility();}
int main()
{
	std::vector <couple::Couple> c;
	give_gifts(c);
	int k;
	std::cout << "Enter the value of k (For k most happy and compatible couples):";
	std::cin >> k;
	sort(c.begin(), c.end(), happy_cmp);
	if(k > c.size())
	{
		std::cout << "k exceeds no of couples\n\n";
		k = c.size();
	}
	std::cout << k <<" most happiest Couples (happiness):\n\n";
	int count = 0;
	for(auto &it : c)
	{
		if(k == count)
			break;
		std::cout << it.get_boy_name() << " " << it.get_girl_name() << " (" << it.get_happiness() <<")" << "\n";
		count++;
	}
	std::cout << "\n\n" << k <<" most compatible Couples (compatibility):\n";
	sort(c.begin(), c.end(), compat_cmp);
	count = 0;
	for(auto &it : c)
	{
		if(k == count)
			break;
		std::cout << it.get_boy_name() << " " << it.get_girl_name() << " (" << it.get_compatibility() <<")" << "\n";
		count++;	}
	return 0;
}