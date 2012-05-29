#ifndef _CACHER_H_
#define _CACHER_H_

#include "hash_table.h"
#include "data_pool.h"

struct cacher_t{
	unsigned state;
	struct data_pool_t* data_pool;
};

struct cacher_t* cacher_new(struct data_pool_t*, struct hash_table_t*);
void cacher_destroy(struct cacher_t*);

#endif /* _CACHER_H_ */
