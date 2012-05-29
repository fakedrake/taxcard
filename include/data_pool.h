#ifndef _DATA_POOL_H_
#define _DATA_POOL_H_

struct data_pool_t{
	unsigned size;
	void* data;
};


struct data_pool_t* data_pool_copy(struct data_pool_t*);
struct data_pool_t* data_pool_new(unsigned);
void data_pool_destroy(struct data_pool_t*);

#endif /* _DATA_POOL_H_ */
