#include "hash_table.h"

int main(int argc, char* argv[])
{
	struct hash_table_t* table = hash_table_initialize(100);
	if (table)
		printf ("Success!\n");
	else
		printf ("Fail!\n");

	return 0;
}
