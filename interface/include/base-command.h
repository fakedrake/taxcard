#ifndef _BASE_COMMAND_H_
#define _BASE_COMMAND_H_


// Do all the basic work so the commands dont have to
class BaseCommand
{
public:
	BaseCommand();
	BaseCommand(string, string, Parser*);
	~BaseCommand();

	string getName();
	string getDoc();
	string getError();

	virtual int get_arg(string)=0;
	virtual string output()=0;
	virtual int execute()=0;

private:
	string _error, _name, _doc;
};

#endif /* _BASE_COMMAND_H_ */
