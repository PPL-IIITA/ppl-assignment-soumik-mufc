// Header file for NormalGirl class

/*
NormalGirl Header file.
Contains info about each NormalGirl.
The attributes: name, attractiveness, intelligence, budget, commit_status
The functions are: 
*/



#ifndef NORMAL_H_
#define NORMAL_H_

#include <string>

namespace normal
{
	class Normal
	{
	private:
		std::string name;
		int attractiveness;
		int intelligence;
		int budget;
		bool commit_status;
		int preference;
	public:
		Normal(std::string, int, int, int, int);
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