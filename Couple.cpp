#include <string>
#include "Couple.h"
#include <cmath>
couple::Couple::Couple(std::string s1, std::string s2, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8)
{
	boy_name = s1;
	girl_name = s2;
	boy_attract = v1;
	girl_attract = v2;
	boy_type = v7;
	girl_type = v8;
	boy_budget = v5;
	girl_budget = v6;
	boy_intel = v3;
	girl_intel = v4;
}
std::string couple::Couple::get_boy_name() const
{
	return boy_name;
}
std::string couple::Couple::get_girl_name() const
{
	return girl_name;
}
double couple::Couple::get_happiness() const
{
	return happiness;
}
int couple::Couple::get_compatibility() const
{
	return compatibility;
}
int couple::Couple::get_boy_type() const
{
	return boy_type;
}
int couple::Couple::get_girl_type() const
{
	return girl_type;
}
int couple::Couple::get_boy_budget() const
{
	return boy_budget;
}
int couple::Couple::get_girl_budget() const
{
	return girl_budget;
}
int couple::Couple::get_boy_attract() const
{
	return boy_attract;
}
int couple::Couple::get_girl_attract() const
{
	return girl_attract;
}
int couple::Couple::get_boy_intel() const
{
	return boy_intel;
}
int couple::Couple::get_girl_intel() const
{
	return girl_intel;
}
double couple::Couple::get_boy_happy() const
{
	return boy_happy;
}
double couple::Couple::get_girl_happy() const
{
	return girl_happy;
}
void couple::Couple::set_happiness()
{
	happiness = girl_happy + boy_happy;
}
void couple::Couple::set_compatibility()
{
	compatibility = abs(boy_intel - girl_intel) + abs(girl_budget - boy_budget) + abs(girl_attract - boy_attract);
}
void couple::Couple::set_girl_happy(double a)
{
	girl_happy = a;
}
void couple::Couple::set_boy_happy(double a)
{
	boy_happy = a;
}