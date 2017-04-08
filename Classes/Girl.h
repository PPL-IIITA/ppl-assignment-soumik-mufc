#ifndef GIRL_H_
#define GIRL_H_

#include <string>

namespace data
{
	class Girl
	{
	private:
		std::string name;
		int attractiveness;
		int intelligence;
		int budget;
		int preference; //* prefernce = {1=attractive, 2=rich, 3=intelligence}
		double happiness;
		bool commit_status;
		int type;
	public:
		Girl(std::string, int, int, int, int, int);
		std::string get_name() const;
		int get_attractiveness() const; 
		int get_intelligence() const;
		int get_budget() const;
		int get_preference() const;
		double get_happiness() const;
		void set_happiness(double);
		bool get_commit_status() const;
		void set_commit_status(bool);
		int get_type() const;
	};
}

#endif