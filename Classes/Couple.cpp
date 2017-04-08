#include "Couple.h"
#include <cmath>
data::Couple::Couple(data::Boy b, data::Girl g) : boy(b), girl(g)
{
	this->happiness = 0.0;
	this->compatibility = 0;
}

void data::Couple::set_happiness()
{
	this->happiness =  girl.get_happiness() + boy.get_happiness();
}

double data::Couple::get_happiness() const
{
	return happiness;
}

int data::Couple::get_compatibility() const
{
	return compatibility;
}

void data::Couple::set_compatibility()
{
	compatibility=  abs(boy.get_intelligence() - girl.get_intelligence()) + abs(girl.get_budget() - boy.get_budget()) + abs(girl.get_attractiveness() - boy.get_attractiveness());
}