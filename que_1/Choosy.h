// Header file for ChoosyGirl class

/*
ChoosyGirl Header file.
Contains info about each ChoosyGirl.
The attributes: name, attractiveness, intelligence, budget, commit_status
The functions are: 
*/



#ifndef CHOOSY_H_
#define CHOOSY_H_

#include <string>

namespace choosy
{
	class Choosy
	{

	private:
		std::string name;
		int attractiveness;
		int intelligence;
		int budget;
		bool commit_status;
		int preference;
	public:
		Choosy(std::string, int, int, int, int);
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