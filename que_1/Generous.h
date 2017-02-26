// Header file for GenerousBoy class

/*
GenerousBoy Header Class.
Contains info about each boy.
The attributes: name, attractiveness, intelligence, budget, minimum attractiveness required, commit_status
The functions are: 
*/



#ifndef GENEROUS_H_
#define GENEROUS_H_

#include <string>

namespace generous
{
	class Generous
	{
	private:
		std::string name;
		int attractiveness;
		int intelligence;
		int budget;
		int min_attr_req;
		bool commit_status;
	public:
		Generous(std::string, int, int, int, int);
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