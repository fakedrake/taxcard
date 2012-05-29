#include "stdlib.h"
#include "mapcar.h"

struct data_pool_t* mapcar(struct hash_table_t* table, void (*iterator)(struct entry_t* ,void*), struct data_pool_t* pool, struct cacher_t* cacher)
{
	unsigned end_state = 0;
	if (cacher) {
		end_state = cacher->state;

		if (table->last->state <= end_state )
			return data_pool_copy(cacher->data_pool);
	}

	struct list_item_t* l;
	for (l = table->last; l && l->state > end_state; l = l->prev)
		iterator(l->token->data, pool);

	if (cacher)
		cacher->data_pool = data_pool_copy (pool);
	return NULL;
}
