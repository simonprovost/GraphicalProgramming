/*
** EPITECH PROJECT, 2017
** hashify
** File description:
** hashb.c created: 07/03/18 13:12
*/

#include "../../include/hashify.h"
#include <stdlib.h>

void hm_add(hashmap_t *hashmap, char *key, void *value)
{
	unsigned int i = hm_hash(hashmap, key);
	bucket_t *bucket = hm_get_bucket(hashmap, key);

	if (bucket == NULL) {
		hm_ll_add(hashmap->data + i, hm_bucket_create(value, key));
		return;
	}
	bucket->value = value;
}

int my_strcmp_hm(char *a, char *b)
{
	int lena = 0;
	int lenb = 0;

	for (; a[lena]; lena++);
	for (; b[lenb]; lenb++);
	if (lena != lenb)
		return (1);
	for (int i = 0; a[i] && b[i]; i++)
		if (a[i] != b[i])
			return (1);
	return (0);
}

bucket_t *hm_get_bucket(hashmap_t *hashmap, char *key)
{
	unsigned int i;
	bucket_t *list;

	if (!key) {
		my_printf("WARNING: HM_GET: KEY PASSED IS NULL !\n");
		return (NULL);
	}
	if (!hashmap) {
		my_printf("WARNING: HM_GET: ASKED FOR UNEXISTING HASHMAP !\n");
		return (NULL);
	}
	i = hm_hash(hashmap, key);
	list = hashmap->data[i];
	while (list != NULL && my_strcmp_hm(list->key, key) != 0) {
		list = list->next;
	}
	if (list == NULL)
		return (NULL);
	return (list);
}

void *hm_get(hashmap_t *hashmap, char *key)
{
	unsigned int i;
	bucket_t *list;

	if (!key) {
		my_printf("WARNING: HM_GET: KEY PASSED IS NULL !\n");
		return (NULL);
	}
	if (!hashmap) {
		my_printf("WARNING: HM_GET: ASKED FOR UNEXISTING HASHMAP !\n");
		return (NULL);
	}
	i = hm_hash(hashmap, key);
	list = hashmap->data[i];
	while (list != NULL && my_strcmp_hm(list->key, key) != 0) {
		list = list->next;
	}
	if (list == NULL)
		return (NULL);
	return (list->value);
}

void bucket_destroy(bucket_t *bucket, hashmap_t *hashmap)
{
	bucket_t *tmp;

	while (bucket) {
		tmp = bucket;
		bucket = bucket->next;
		free(tmp->key);
		hashmap->destroyer(tmp->value);
		free(tmp);
	}
}
