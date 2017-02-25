// Header file for Miser class

/*
MiserBoy Header file.
Contains info about each MiserBoy.
The attributes: name, attractiveness, intelligence, budget, minimum attractiveness required, commit_status
The functions are: 
*/



#ifndef MISER_H_
#define MISER_H_

#include <string>

namespace miser
{
	class Miser
	{
	private:
		std::string name;
		int attractiveness;
		int intelligence;
		int budget;
		int min_attr_req;
		bool commit_status;
	public:
		Miser(std::string, int, int, int, int);
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