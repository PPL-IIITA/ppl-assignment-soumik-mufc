#include "Boy.h"
#include <string>

data::Boy::Boy(std::string name, int attractiveness, int intelligence, int budget, int min_attr_req, int type)
{
	this->name = name;
	this->attractiveness = attractiveness;
	this->intelligence = intelligence;
	this->budget = budget;
	this->min_attr_req = min_attr_req;
	this->happiness = 0;
	this->commit_status = false;
	this->type = type;
}

std::string data::Boy::get_name() const
{
	return name;
}

int data::Boy::get_attractiveness() const
{
	return attractiveness;
}

int data::Boy::get_intelligence() const
{
	return intelligence;
}

int data::Boy::get_budget() const
{
	return budget;
}

int data::Boy::get_min_attr_req() const
{
	return min_attr_req;
}

double data::Boy::get_happiness() const
{
	return happiness;
}
bool data::Boy::get_commit_status() const
{
	return commit_status;
}
void data::Boy::set_commit_status(bool stat)
{
	this->commit_status = stat;
}
int data::Boy::get_type() const
{
	return type;
}

void data::Boy::set_happiness(double h)
{
	happiness = h;
}