#include "Choosy.h"
#include <string>

choosy::Choosy::Choosy(std::string name, int attractiveness, int intelligence, int budget, int preference)
{
	this->name = name;
	this->attractiveness = attractiveness;
	this->intelligence = intelligence;
	this->budget	= budget;
	this->commit_status = false;
	this->preference = preference;
}

std::string choosy::Choosy::getname() const
{
	return name;
}

int choosy::Choosy::get_attractiveness() const
{
	return attractiveness;
}

int choosy::Choosy::get_intelligence() const
{
	return intelligence;
}
int choosy::Choosy::get_budget() const
{
	return budget;
}
bool choosy::Choosy::get_commit_status() const
{
	return commit_status;
}
void choosy::Choosy::set_commit_status(bool stat)
{
	this->commit_status = stat;
}
int choosy::Choosy::get_preference() const
{
	return preference;
}