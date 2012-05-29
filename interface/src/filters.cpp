#include "filters.h"
#include <sstream>
#include <string>

using namespace std;

bool FilterBase::is_valid()
{
	return _valid;
}

FilterYear::FilterYear( string str ,bool neg )
{
	stringstream ss;
	ss<<str;
	ss>>hex>>_year;

	_neg = neg;
}

bool FilterYear::test( entry_t* entry)
{
	return (_neg==true) ^ (entry->date.year == _year);
}

FilterDay::FilterDay( string str ,bool neg )
{
	stringstream ss;
	ss<<str;
	ss>>hex>>_day;

	_neg = neg;
}

bool FilterDay::test( entry_t* entry)
{
	return (_neg==true) ^ (entry->date.day == _day);
}

FilterProduct::FilterProduct( string str ,bool neg )
{
	_product = str;

	_neg = neg;
}

bool FilterProduct::test( entry_t* entry)
{
	product_t* p = entry->products.list_head;
	while (p) {
		if ((_product == p.id) ^ _neg)
			return true;
		p = p->next;
	}
}

FilterVendor::FilterVendor( string str ,bool neg )
{
	_vendor == str;

	_neg = neg;
}

bool FilterVendor::test( entry_t* entry)
{
	return (_neg==true) ^ (_vendor == entry->vedor);
}
