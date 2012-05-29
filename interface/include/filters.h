#ifndef _FILTERS_H_
#define _FILTERS_H_

// To add a filter type add the class here, its implementation in
// filters.cpp and its creation in filterFactory in filter.cpp

class FilterBase
{
public:
	FilterBase();
	~FilterBase();

	virtual bool test(entry_t*);
	bool is_valid();

private:
	bool _valid;
};

class FilterYear : public FilterBase
{
public:
	FilterYear(string, bool);
	~FilterYear();

	bool test(entry_t*);

private:
	bool _valid, _neg;
	string _value;
};

class FilterDay : public FilterBase
{
public:
	FilterDay(string, bool);
	~FilterDay();

	bool test(entry_t*);

private:
	bool _valid, _neg;
	string _value;
};

class FilterProduct : public FilterBase
{
public:
	FilterProduct(string, bool);
	~FilterProduct();

	bool test(entry_t*);

private:
	bool _valid, _neg;
	string _value;
};

class FilterVendor : public FilterBase
{
public:
	FilterVendor(string, bool);
	~FilterVendor();

	bool test(entry_t*);

private:
	bool _valid, _neg;
	string _value;
};

#endif /* _FILTERS_H_ */
