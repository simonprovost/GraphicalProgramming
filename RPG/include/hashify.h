/*
** EPITECH PROJECT, 2017
** hashify
** File description:
** header file
*/

#ifndef HASHIFY_H_
#define HASHIFY_H_
#include "my.h"

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

/// Create a hashmap   (recommanded size: 1024)
///
/// more size -> more perf but take more memory
///
/// less size -> less perf but take less memory
/// \param size size of the hashmap
/// \return created hashmap pointer
hashmap_t *hm_create(unsigned int size, void (*fptr)());

/// Send bucket value to a given destroy function and free all the map
/// (at this time, free only the main pointer and
/// the array)
/// \param hashmap hashmap
void hm_destroy(hashmap_t *hashmap);

/// add something to the hashmap
/// \param hashmap hashmap
/// \param key key (index equivalent)
/// \param value value
void hm_add(hashmap_t *hashmap, char *key, void *value);

/// find an item in hashmap
/// \param hashmap hashmap
/// \param key key (index equivalent)
/// \return value
void *hm_get(hashmap_t *hashmap, char *key);

/////////////////////////////////////////////
////      DO NOT USE THESE FUNCTIONS     ////
/////////////////////////////////////////////

unsigned int hm_hash(hashmap_t *hashmap, char *key);
bucket_t *hm_bucket_create(void *value, char *key);
void hm_ll_add(bucket_t **list, bucket_t *bucket);
int my_strcmp_hm(char *a, char *b);
bucket_t *hm_get_bucket(hashmap_t *hashmap, char *key);
void bucket_destroy(bucket_t *bucket, hashmap_t *hashmap);

#endif /* !HASHIFY_H_ */
