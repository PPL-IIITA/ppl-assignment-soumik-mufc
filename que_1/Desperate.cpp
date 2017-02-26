#include "Desperate.h"
#include <string>

desperate::Desperate::Desperate(std::string name, int attractiveness, int intelligence, int budget, int preference)
{
	this->name = name;
	this->attractiveness = attractiveness;
	this->intelligence = intelligence;
	this->budget	= budget;
	this->commit_status = false;
	this->preference = preference;
}
std::string desperate::Desperate::getname() const
{
	return name;
}
int desperate::Desperate::get_attractiveness() const
{
	return attractiveness;
}
int desperate::Desperate::get_intelligence() const
{
	return intelligence;
}
int desperate::Desperate::get_budget() const
{
	return budget;
}

bool desperate::Desperate::get_commit_status() const
{
	return commit_status;
}
void desperate::Desperate::set_commit_status(bool stat)
{
	this->commit_status = stat;
}
int desperate::Desperate::get_preference() const
{
	return preference;
}