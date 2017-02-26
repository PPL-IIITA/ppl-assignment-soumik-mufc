#ifndef HELPER_H__
#define HELPER_H_
#include "Miser.h"
#include "Generous.h"
#include "Geeky.h"
#include "Choosy.h"
#include "Normal.h"
#include "Desperate.h"
#include <vector>
class Helper
{
public:
	friend void scan_data(std::vector<miser::Miser> &vb1, std::vector<generous::Generous> &vb2, std::vector<geeky::Geeky> &vb3, std::vector<choosy::Choosy> &vg1, std::vector<normal::Normal> &vg2, std::vector<desperate::Desperate> &vg3);
	friend void display(const std::vector<miser::Miser> &vb1, const std::vector<generous::Generous> &vb2, const std::vector<geeky::Geeky> &vb3, const std::vector<choosy::Choosy> &vg1, const std::vector<normal::Normal> &vg2,const std::vector<desperate::Desperate> &vg3);
	friend void make_couple(std::vector<miser::Miser> &vb1, std::vector<generous::Generous> &vb2, std::vector<geeky::Geeky> &vb3, std::vector<choosy::Choosy> &vg1, std::vector<normal::Normal> &vg2, std::vector<desperate::Desperate> &vg3, std::vector <std::pair<std::string, std::string>> &couples);
	friend int maximum( int a, int b, int c );
	friend void store_couples(std::vector <std::pair<std::string, std::string>> &couples);
	
};

void scan_data(std::vector<miser::Miser> &vb1, std::vector<generous::Generous> &vb2, std::vector<geeky::Geeky> &vb3, std::vector<choosy::Choosy> &vg1, std::vector<normal::Normal> &vg2, std::vector<desperate::Desperate> &vg3);

void display(const std::vector<miser::Miser> &vb1, const std::vector<generous::Generous> &vb2, const std::vector<geeky::Geeky> &vb3, const std::vector<choosy::Choosy> &vg1, const std::vector<normal::Normal> &vg2,const std::vector<desperate::Desperate> &vg3);

void make_couple(std::vector<miser::Miser> &vb1, std::vector<generous::Generous> &vb2, std::vector<geeky::Geeky> &vb3, std::vector<choosy::Choosy> &vg1, std::vector<normal::Normal> &vg2, std::vector<desperate::Desperate> &vg3, std::vector <std::pair<std::string, std::string>> &couples);

int maximum( int a, int b, int c );

void store_couples(std::vector <std::pair<std::string, std::string>> &couples);

#endif
