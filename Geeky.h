// Header file for GeekyBoy class

/*
GeekyBoy Header Class.
Contains info about each boy.
The attributes: name, attractiveness, intelligence, budget, minimum attractiveness required, commit_status
The functions are: 
*/



#ifndef GEEKY_H_
#define GEEKY_H_

#include <string>

namespace geeky
{
	class Geeky
	{
	private:
		std::string name;
		int attractiveness;
		int intelligence;
		int budget;
		int min_attr_req;
		bool commit_status;
	public:
		Geeky(std::string, int, int, int, int);
		std::string getname() const;
		int get_attractiveness() const;
		int get_intelligence() const;
		int get_budget() const;
		int get_min_attr_req() const;
		bool get_commit_status() const;
		void set_commit_status(bool);
	};
}

#endif