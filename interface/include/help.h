#ifndef _HELP_H_
#define _HELP_H_

class HelpCommand : public BaseCommand
{
public:
	HelpCommand();
	HelpCommand(Parser* p) : BaseCommand(p);
	virtual ~HelpCommand();

	int get_arg(string); // should find a way to give help the abuility to create classes
	string output();
	void execute();
};

#endif /* _HELP_H_ */
