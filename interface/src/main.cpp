#include "parser.h"

int main(int argc, char *argv[])
{
	Parser p = new Parser();
	getline(cin, input_line);
	p.read(input_line);
	p.eval();
	cout<< p.print();

	return 0;
}
