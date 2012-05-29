#include "parser.h"
#define HASH_TABLE_INIT_SIZE 50000

Parser::Parser()
{
	extern "C" {
		_hash_table = new_hash_table(HASH_TABLE_INIT_SIZE);
	}
	_cmd = new BaseCommand();
}

virtual ~Parser::Parser()
{
	destroy _cmd;
}

BaseCommand* Parser::getCommand(string s)
{
	if (s == "filter") {
		return new FilterCommand(this);
	} else if ( s == "help") {
		return  new HelpCommand(this);
	} else {
		return NULL;
	}
}

void Parser::read(string s)
{
	stringstream ss;
	string tmp;
	ss.str(s);
	destroy _cmd;

	ss>>tmp;
	_cmd = getCommand(tmp);

	if (!_cmd) {
		_error = "Invelid command: "+tmp;
		return;
	}

	while (!ss.empty()) {
		ss>>tmp;
		if (!_cmd->get_arg(tmp)) {
			_error = _cmd->getName": "+_cmd->getError();
			return;
		}
	}
}

}

int Parser::eval()
{
	return _cmd->execute();
}

string Parser::print()
{
	if ( !_error.empty() ) return _error;
	if ( !cmd->getError().empty() ) return cmd->getError();

	cmd->output();
}
