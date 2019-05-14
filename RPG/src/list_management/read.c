/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int read_bucket(window_t *window, game_t *game, bucket_t *bucket, int (*fptr)())
{
	bucket_t *tmp = bucket;
	int my_errno = 0;

	while (tmp) {
		if (!window && !game)
			my_errno = fptr(tmp);
		if (!window && game) {
			my_errno = fptr(tmp, game);
		} else if (window && !game) {
			my_errno = fptr(tmp, window);
		} else {
			my_errno = fptr(tmp, window, game);
		}
		if (my_errno != 0)
			return (my_errno);
		tmp = tmp->next;
	}
	return (0);
}

int read_hashmap(window_t *window, game_t *game, hashmap_t *hashmap,
								int (*fptr)())
{
	bucket_t *tmp;
	int my_errno = 0;

	for (unsigned int i = 0; i != hashmap->size; i++) {
		tmp = hashmap->data[i];
		my_errno = read_bucket(window, game, tmp, fptr);
		if (my_errno != 0)
			return (my_errno);
	}
	return (0);
}
