#ifndef COUPLE_H_
#define COUPLE_H_
#include "Girl.h"
#include "Boy.h"

namespace data
{
	class Couple
	{
	private:
		
		double happiness;
		int compatibility;

	public:
		data::Boy boy;
		data::Girl girl;
		Couple(data::Boy, data::Girl);
		void set_happiness();
		double get_happiness() const;
		int get_compatibility() const;
		void set_compatibility();
	};
}

#endif