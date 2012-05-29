#ifndef _PARSER_H_
#define _PARSER_H_

#include "base-command.h"

extern "C" {
#include "hash_table.h"
}

class Parser
{
public:
	Parser();
	virtual ~Parser();

	void read(string);
	int eval();
	string print();

private:
	BaseCommand *_cmd;
	string _error;
	extern "C" struct hash_table_t* _table;
};

#endif /* _PARSER_H_ */
