#include "Geeky.h"
#include <string>

geeky::Geeky::Geeky(std::string name, int attractiveness, int intelligence, int budget, int min_attr_req)
{
	this->name = name;
	this->attractiveness = attractiveness;
	this->intelligence = intelligence;
	this->budget = budget;
	this->min_attr_req = min_attr_req;
	this->commit_status = false;
}

std::string geeky::Geeky::getname() const
{
	return name;
}

int geeky::Geeky::get_attractiveness() const
{
	return attractiveness;
}

int geeky::Geeky::get_intelligence() const
{
	return intelligence;
}
int geeky::Geeky::get_budget() const
{
	return budget;
}
int geeky::Geeky::get_min_attr_req() const
{
	return min_attr_req;
}
bool geeky::Geeky::get_commit_status() const
{
	return commit_status;
}
void geeky::Geeky::set_commit_status(bool stat)
{
	this->commit_status = stat;
}