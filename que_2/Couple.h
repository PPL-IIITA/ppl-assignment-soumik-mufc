#ifndef COUPLE_H_
#define COUPLE_H_ 
#include <string>

namespace couple
{
	class Couple
	{
	private:
		std::string boy_name;
		std::string girl_name;
		int boy_type;
		int girl_type;
		int boy_budget;
		int girl_budget;
		int boy_attract;
		int girl_attract;
		int boy_intel;
		int girl_intel;
		double boy_happy;
		double girl_happy;
		double happiness;
		int compatibility;
	public:
		Couple(std::string, std::string, int, int, int, int, int, int, int, int);
		std::string get_boy_name() const;
		std::string get_girl_name() const;
		double get_happiness() const;
		int get_compatibility() const;
		int get_boy_type() const;
		int get_girl_type() const;
		int get_boy_budget() const;
		int get_girl_budget() const;
		int get_boy_attract() const;
		int get_girl_attract() const;
		int get_boy_intel() const;
		int get_girl_intel() const;
		double get_boy_happy() const;
		double get_girl_happy() const;
		void set_boy_happy(double);
		void set_girl_happy(double);
		void set_happiness();
		void set_compatibility();
	};
}
#endif