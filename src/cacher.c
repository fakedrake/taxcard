#include<malloc.h>
#include "cacher.h"

// NULL pool and table make empty cachers
struct cacher_t* cacher_new(struct data_pool_t* pool, struct hash_table_t* table)
{
	struct cacher_t *ret = (struct cacher_t*) malloc(sizeof(struct cacher_t));
	if (!ret) return NULL;

	ret->data_pool = data_pool_copy(pool);
	if (table)
		ret->state = table->state;
	else
		ret->state = 0;
	return ret;
}

void cacher_destroy(struct cacher_t* c)
{
	data_pool_destroy(c->data_pool);
	free(c);
}
