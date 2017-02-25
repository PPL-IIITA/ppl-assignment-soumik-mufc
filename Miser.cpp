#include "Miser.h"
#include <string>

miser::Miser::Miser(std::string name, int attractiveness, int intelligence, int budget, int min_attr_req)
{
	this->name = name;
	this->attractiveness = attractiveness;
	this->intelligence = intelligence;
	this->budget	= budget;
	this->min_attr_req = min_attr_req;
	this->commit_status = false;
}

std::string miser::Miser::getname() const
{
	return name;
}

int miser::Miser::get_attractiveness() const
{
	return attractiveness;
}

int miser::Miser::get_intelligence() const
{
	return intelligence;
}
int miser::Miser::get_budget() const
{
	return budget;
}
int miser::Miser::get_min_attr_req() const
{
	return min_attr_req;
}
bool miser::Miser::get_commit_status() const
{
	return commit_status;
}
void miser::Miser::set_commit_status(bool stat)
{
	this->commit_status = stat;
}