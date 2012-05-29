
BaseCommand::BaseCommand()
{
}

BaseCommand::BaseCommand(string name, string doc, Parser* p)
{
	_valid = (!name.empty() && p);
	_name = name;
	_doc = doc;
	_parser = p;
}

BaseCommand::~BaseCommand()
{
}


string BaseCommand::getName()
{
	return _name;
}

string BaseCommand::getDoc()
{
	return _doc;
}

string BaseCommand::getError()
{
	return _error;
}
