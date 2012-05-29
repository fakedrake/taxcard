#ifndef _ENTRY_H_
#define _ENTRY_H_

#include "config.h"
#include "hash_table.h"

typedef unsigned company_id_t;

struct product_t{
	struct __product_t * next;
	char id [PRODUCT_ID_SIZE];
};

struct product_list_t{
	unsigned count;
	struct product_t* list_head;
};

struct date_t {
	unsigned short year, day;
};

struct entry_t {
	struct list_item_t* list_item;
	struct date_t date;
	int cost;
	char vendor[VENDOR_SIZE];
	company_id_t company_id;
	struct product_list_t products;
};

#endif /* _ENTRY_H_ */
