#include "Girl.h"
#include <string>

data::Girl::Girl(std::string name, int attractiveness, int intelligence, int budget, int preference)
{
	this->name = name;
	this->attractiveness = attractiveness;
	this->intelligence = intelligence;
	this->budget = budget;
	this->preference = preference;
	this->happiness = 0;
	this->commit_status = false;
}

std::string data::Girl::get_name() const
{
	return name;
}

int data::Girl::get_attractiveness() const
{
	return attractiveness;
}

int data::Girl::get_intelligence() const
{
	return intelligence;
}

int data::Girl::get_budget() const
{
	return budget;
}

int data::Girl::get_preference() const
{
	return preference;
}

double data::Girl::get_happiness() const
{
	return happiness;
}

bool data::Girl::get_commit_status() const
{
	return commit_status;
}

void data::Girl::set_commit_status(bool stat)
{
	this->commit_status = stat;
}