#ifndef _FILTER_H_
#define _FILTER_H_

extern "C" {
#include "entry.h"
}

#include "base-command.h"


class FilterCommand : public BaseCommand
{
public:
	FilterCommand(Parser* p) : BaseCommand("filter", "Filters entries that are selected. No arguments select all entries.", p) {};
	~FilterCommand();

	int get_arg(string);
	string output();
	void execute();

private:
	FilterBase* filterFactory(string);
	list<Filter*> _filters;
	struct hash_table_t* _table;
};

#endif /* _FILTER_H_ */
