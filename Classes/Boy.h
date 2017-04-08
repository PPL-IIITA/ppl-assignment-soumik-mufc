#ifndef BOY_H_
#define BOY_H_

#include <string>

namespace data
{
	class Boy
	{
	private:
		std::string name;
		int attractiveness;
		int intelligence;
		int budget;
		int min_attr_req;
		double happiness;
		bool commit_status;
		int type;
	public:
		Boy(std::string , int, int, int, int, int);
		std::string get_name() const;
		int get_attractiveness() const; 
		int get_intelligence() const;
		int get_budget() const;
		int get_min_attr_req() const;
		double get_happiness() const;
		void set_happiness(double);
		bool get_commit_status() const;
		void set_commit_status(bool);
		int get_type() const;
	};
}

#endif