#include <malloc.h>
#include <string.h>
#include "hash_table.h"

#define INLINE inline

struct position_t hash_function(const char* id, struct hash_table_t* table)
{
	int i;
	struct position_t ret;
	ret.index = 5381;
	for(i=0; i<CODE_SIZE && id[i]; i++) {
		ret.index = ((ret.index<<5) + ret.index) + id[i];
	}
	ret.index %= MAX_ALLOWED_ENTRIES;

	ret.table = table;
	ret.lookups = 0;
	return ret;
}

/* There is an off chance that to set only the pointers to NULL may be
   better */
INLINE void tokens_invalidate ( struct token_t * p, unsigned size)
{
	memset( p, 0, size);
}

struct hash_table_t* hash_table_initialize (unsigned size)
{
	struct hash_table_t *table;
	table = (struct hash_table_t*) malloc (sizeof(struct hash_table_t));
	if (!table)
		return NULL;

	table->data = (struct token_t*) malloc (sizeof(struct token_t)*size);
	if (!table->data)
		return NULL;

	tokens_invalidate ( table->data, size);

	table->state = 0;
	table->last = NULL;
	table->size = table->free = size;
	return table;
}

/* Attention! this is unsafe!*/
INLINE error_t next_pos(struct position_t* p)
{
	INC_INDEX(p->index, p->lookups);
	return TC_OK;
}

error_t accomodate(const struct position_t* p)
{
	if (p->index < p->table->size)
		return TC_OK;


	void* tmp = realloc(p->table->data, sizeof(struct token_t) * ALIGN(p->index));
	if (!tmp)
		return TC_MEMERR;

	p->table->data = (struct token_t*) tmp;

	tokens_invalidate (p->table->data + p->table->size, p->table->size - ALIGN(p->index));
	p->table->free += ALIGN(p->index) - p->table->size;
	p->table->size = ALIGN(p->index);

	return TC_OK;
}

/* Check if pos is available */
error_t availability(const struct position_t* p)
{
	if (p->index > p->table->size)
		return TC_MEMERR;

	if (!p->table->data[p->index].data)
		return TC_OK;
	else
		return TC_FULL;
}

struct token_t token_new(struct entry_t *entry, const char* c)
{
	struct token_t ret;
	memcpy( ret.id, c, CODE_SIZE );
	ret.data = entry;
	return ret;
}

void entry_destroy( struct entry_t* entry)
{
	free(entry);
}

error_t rm_entry(struct position_t p)
{
	struct token_t *token = p.table->data+p.index;
	struct entry_t *entry = token->data;
	struct list_item_t *it = entry->list_item;

	// this is some C weirdness: remember that as far as it->next
	// is concerned struct list_item_t is undefined

	// previous entry before the next one
	it->next->prev = it->prev;
	// put next entry after previous one
	it->prev->next = it->next;

	free(it);
	entry_destroy (entry);
	tokens_invalidate(token, 1);
	token->data = NULL;
	return TC_OK;
}

error_t add_entry(char* id, struct entry_t* entry, struct hash_table_t* table)
{
	struct position_t p = hash_function(id, table);

	// Make way fo the token
	while (availability(&p) == TC_FULL) next_pos(&p);
	if (accomodate (&p))
		return TC_MEMERR;

	// Place the token
	table->data[p.index] = token_new(entry, id);

	// Add entry-token to the list
	struct list_item_t* ltmp = (struct list_item_t *) malloc(sizeof(struct list_item_t));

	// Insert ltmp after table->last
	ltmp->next = NULL;
	ltmp->prev = table->last;
	table->last->next = ltmp;
	ltmp->token = table->data+p.index;

	// Now ltmp is the last
	table->last = ltmp;

	table->state++;
	ltmp->state = table->state;
	table->free--;
	return TC_OK;
}

/* Search form the hash to the next non-full position */
struct position_t get_entry(char *id, struct hash_table_t* table)
{
	struct position_t p;
	for ( p = hash_function(id, table); availability(&p) == TC_FULL; next_pos(&p)) {
		if ( !strcmp(table->data[p.index].id , id) )
			return p;
	}
	p.index = -1;
	return p;
}

error_t hash_table_destroy (struct hash_table_t* table)
{
	// l will iterate over the list setting a timebomb on its path
	// which will destroy the list items
	struct list_item_t *l, *time_bomb;

	for (l = table->last; l; l = l->prev) {
		entry_destroy (l->token->data);
		time_bomb = l;
		l = l->prev;
		if (time_bomb) free (time_bomb);
	}

	free(table->data);
	free(table);
	return TC_OK;
}


struct entry_t* entry_from_pos(struct position_t p)
{
	return p.table->data[p.index].data;
}
