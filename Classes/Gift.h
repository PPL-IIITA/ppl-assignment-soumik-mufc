#ifndef GIFT_H_
#define GIFT_H_
#include <string>

/* Maybe status variable is not needed;
*/
namespace data
{
	class Gift
	{
	private:
		std::string name;
		int price;
		int value;
		int type;
		int data1;
		int data2;
		bool status;
	public:
		Gift(std::string, int, int, int, int, int);
		std::string get_name() const;
		int get_price() const;
		int get_value() const;
		int get_type() const;
		int get_data1() const;
		int get_data2() const;
		bool get_status() const;
		void set_status(bool);
	};
}

#endif