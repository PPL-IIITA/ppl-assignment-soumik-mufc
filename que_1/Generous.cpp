#include "Generous.h"
#include <string>

generous::Generous::Generous(std::string name, int attractiveness, int intelligence, int budget, int min_attr_req)
{
	this->name = name;
	this->attractiveness = attractiveness;
	this->intelligence = intelligence;
	this->budget	= budget;
	this->min_attr_req = min_attr_req;
	this->commit_status = false;
}

std::string generous::Generous::getname() const
{
	return name;
}

int generous::Generous::get_attractiveness() const
{
	return attractiveness;
}

int generous::Generous::get_intelligence() const
{
	return intelligence;
}
int generous::Generous::get_budget() const
{
	return budget;
}
int generous::Generous::get_min_attr_req() const
{
	return min_attr_req;
}
bool generous::Generous::get_commit_status() const
{
	return commit_status;
}
void generous::Generous::set_commit_status(bool stat)
{
	this->commit_status = stat;
}