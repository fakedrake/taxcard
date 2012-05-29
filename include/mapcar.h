#ifndef _MAPCAR_H_
#define _MAPCAR_H_
#include "hash_table.h"
#include "entry.h"
#include "cacher.h"
#include "data_pool.h"

struct data_pool_t* mapcar(struct hash_table_t*, void (*)(struct entry_t*,void*), struct data_pool_t*, struct cacher_t*);

#endif /* _MAPCAR_H_ */
