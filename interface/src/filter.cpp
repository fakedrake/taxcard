#include "filters.h"
#include "filter.h"


FilterCommand::~FilterCommand()
{
	// Clear list
	FilterBase *tmp;
	for (list<FilterBase*>::iterator it = _filters.begin(); it!=_filters.end(); it++) {
		tmp = *it;
		delete tmp;
	}

	delete _filters;
}

int FilterCommand::get_arg(string str)
{
	BaseFilter* flt = filterFactory(str);
	if (!flt) {
		_error = "Invalid argument: "+str;
		return -1;
	}

	_filters.push_back(flt);
	return 0;
}

string FilterCommand::output()
{
}

void FilterCommand::execute()
{
	bool cleared;
	list_item_t **ref = &(_table->filtered), *tmp;

	// exec the case where filter is ID

	if (!*ref) {
		cleared = true;
		*ref = last;
	}

	// ref is a reference to the next valid entry. This reference
	// is actually the 'next' reference of a member of a connected.
	// list Once assigned it is updated.
	while (*ref) {
		if ( _valid_entry((*ref)->token->data) ) {
			// update ref
			ref = &((*ref)->filter_next);

			// if cleared *ref is completely batshit
			if (cleared)
				(*ref)->prev;
		} else {
			*ref = (cleared ? (*ref)->prev: (*ref)->filter_next);
		}
	}
}

BaseFilter* FilterCommand::filterFactory(string str)
{
	bool nay = false;
	if (str[0] == '!') {
		nay = true;
		str.erase(0,1);
	}

	string id, val;
	istringstream sf(str);
	getline (sf, id, '=');
	getline (sf, val, '=');

	if (id = "year")
		return new FilterYear(val, nay);
	else if (id == "day")
		return new FilterDay (val, nay);
	else if (id == "vendor")
		return new FilterVendor (val, nay);
	else if (id == "product")
		return new FilterProduct (val, nay);
	else
		return NULL;
}

bool FilterCommand::_valid_entry(entry_t* e)
{
	for (list<FilterBase*>::iterator it = _filters.begin(); it!=_filters.end(); it++)
		if ( !(*it)->test(e) ) return false;
	return true;
}
}
