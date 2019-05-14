/*
** EPITECH PROJECT, 2017
** hashify
** File description:
** hash.c created: 05/03/18 14:11
*/

#include "../../include/hashify.h"
#include "../../include/my.h"
#include <stdlib.h>

hashmap_t *hm_create(unsigned int size, void (*fptr)())
{
	hashmap_t *hashmap = malloc(sizeof(hashmap_t));

	if (!hashmap)
		return (NULL);
	hashmap->size = size;
	hashmap->destroyer = fptr;
	hashmap->data = malloc(sizeof(*(hashmap->data)) * size);
	if (!hashmap->data)
		return (NULL);
	for (unsigned int i = 0; i < size; ++i)
		hashmap->data[i] = NULL;
	return (hashmap);
}

void hm_destroy(hashmap_t *hashmap)
{
	for (int i = 0; i < hashmap->size; i++) {
		if (hashmap->data[i]) {
			bucket_destroy(hashmap->data[i], hashmap);
		}
	}
	free(hashmap->data);
	free(hashmap);
}

unsigned int hm_hash(hashmap_t *hashmap, char *key)
{
	unsigned int i = 0;

	while (*key) {
		i += *key;
		key++;
	}
	return (i % hashmap->size);
}

bucket_t *hm_bucket_create(void *value, char *key)
{
	bucket_t *new = malloc(sizeof(*new));

	new->key = my_strdup(key);
	new->value = value;
	new->next = NULL;
	return (new);
}

void hm_ll_add(bucket_t **list, bucket_t *bucket)
{
	bucket->next = *list;
	*list = bucket;
}
