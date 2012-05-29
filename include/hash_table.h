#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include "error.h"
#include "config.h"
#include "entry.h"

struct token_t{
	char id[CODE_SIZE];
	struct entry_t* data;
};

struct list_item_t {
	struct list_item_t *prev, *next, filter_next*;
	unsigned state;
	struct token_t* token;
};

struct hash_table_t{
	unsigned state;
	struct token_t* data;
	unsigned size, free;
	struct list_item_t *last, *filtered;
};

struct position_t{
	struct hash_table_t* table;
	unsigned index, lookups;
};

struct position_t hash_function(const char*, struct hash_table_t*);
struct hash_table_t* hash_table_initialize (unsigned);
error_t availability(const struct position_t*);
void entry_destroy( struct entry_t*);
error_t rm_entry(struct position_t);
error_t add_entry(char*, struct entry_t*, struct hash_table_t*);
struct position_t get_entry(char *, struct hash_table_t*);
error_t hash_table_destroy (struct hash_table_t*);
struct entry_t* entry_from_pos(struct position_t );

#endif /* _TYPES_H_ */
