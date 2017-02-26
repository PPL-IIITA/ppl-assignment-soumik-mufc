#include "Normal.h"
#include <string>

normal::Normal::Normal(std::string name, int attractiveness, int intelligence, int budget, int preference)
{
	this->name = name;
	this->attractiveness = attractiveness;
	this->intelligence = intelligence;
	this->budget	= budget;
	this->commit_status = false;
	this->preference = preference;
}

std::string normal::Normal::getname() const
{
	return name;
}

int normal::Normal::get_attractiveness() const
{
	return attractiveness;
}

int normal::Normal::get_intelligence() const
{
	return intelligence;
}
int normal::Normal::get_budget() const
{
	return budget;
}

bool normal::Normal::get_commit_status() const
{
	return commit_status;
}
void normal::Normal::set_commit_status(bool stat)
{
	this->commit_status = stat;
}
int normal::Normal::get_preference() const
{
	return preference;
}