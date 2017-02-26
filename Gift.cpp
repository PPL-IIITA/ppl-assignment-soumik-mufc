#include <string>
#include "Gift.h"

gift::Gift::Gift(std::string name, int price, int value, int type, int data1, int data2)
{
	this->name = name;
	this->price = price;
	this->value = value;
	this->type = type;
	this->data1 = data1;
	this->data2 = data2;
	this->status = false;
}

std::string gift::Gift::get_name() const
{
	return name;
}
int gift::Gift::get_price() const
{
	return price;
}
int gift::Gift::get_value() const
{
	return value;
}
int gift::Gift::get_type() const
{
	return type;
}
int gift::Gift::get_data1() const
{
	return data1;
}
int gift::Gift::get_data2() const
{
	return data2;
}
bool gift::Gift::get_status() const
{
	return status;
}
void gift::Gift::set_status(bool status)
{
	this->status = status;
}



