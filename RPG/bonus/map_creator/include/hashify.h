/*
** EPITECH PROJECT, 2017
** hashify
** File description:
** header file
*/

#ifndef HASHIFY_H_
#define HASHIFY_H_
#include "../../../include/my.h"

#define VERSION "1.0"

struct bucket_s {
	char *key;
	void *value;
	struct bucket_s *next;
};

struct hashmap_s {
	unsigned int size;
	void (*destroyer)();
	struct bucket_s **data;
};

typedef struct bucket_s bucket_t;
typedef struct hashmap_s hashmap_t;

hashmap_t *hm_create(unsigned int size, void (*fptr)());
void hm_destroy(hashmap_t *hashmap);
void hm_add(hashmap_t *hashmap, char *key, void *value);
void *hm_get(hashmap_t *hashmap, char *key);
unsigned int hm_hash(hashmap_t *hashmap, char *key);
bucket_t *hm_bucket_create(void *value, char *key);
void hm_ll_add(bucket_t **list, bucket_t *bucket);
int my_strcmp_hm(char *a, char *b);
bucket_t *hm_get_bucket(hashmap_t *hashmap, char *key);
void bucket_destroy(bucket_t *bucket, hashmap_t *hashmap);

#endif /* !HASHIFY_H_ */
