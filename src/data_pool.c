#include <string.h>
#include <malloc.h>
#include "data_pool.h"

struct data_pool_t* data_pool_new(unsigned size)
{
	struct data_pool_t* ret = (struct data_pool_t*) malloc(sizeof(struct data_pool_t));
	if (!ret) return NULL;
	ret->size = size;
	ret->data = malloc(size);
	if(!ret->data) {
		free(ret);
		return NULL;
	}
}

struct data_pool_t* data_pool_copy (struct data_pool_t * pool)
{
	struct data_pool_t* ret = (struct data_pool_t*) malloc (sizeof(struct data_pool_t));
	if (!ret)
		return NULL;

	ret->size = pool->size;
	ret->data = malloc(pool->size);
	if(!ret->data) {
		free(ret);
		return NULL;
	}

	memcpy(ret->data, pool->data, pool->size);
	return ret;
}

void data_pool_destroy (struct data_pool_t* pool)
{
	free(pool->data);
	free(pool);
}
