#include "Couple.h"

data::Couple::Couple(data::Boy b, data::Girl g) : boy(b), girl(g)
{
	this->happiness = 0.0;
	this->compatibility = 0;
}

void data::Couple::set_happiness()
{

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

}