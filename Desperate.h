// Header file for DesperateGirl class

/*
DesperateGirl Header file.
Contains info about each DesperateGirl.
The attributes: name, attractiveness, intelligence, budget, commit_status
The functions are: 
*/



#ifndef DESPERATE_H_
#define DESPERATE_H_

#include <string>

namespace desperate
{
	class Desperate
	{
	private:
		std::string name;
		int attractiveness;
		int intelligence;
		int budget;
		bool commit_status;
		int preference;
	public:
		Desperate(std::string, int, int, int, int);
		std::string getname() const;
		int get_attractiveness() const;
		int get_intelligence() const;
		int get_budget() const;
		bool get_commit_status() const;
		void set_commit_status(bool);
		int get_preference() const;
	};
}

#endif