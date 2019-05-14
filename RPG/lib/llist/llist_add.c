/*
** EPITECH PROJECT, 2017
** linked_list_lib
** File description:
** my_llist_create.c
*/

#include <stddef.h>
#include "../../include/llist.h"

node_t *add_to_llist(char *key, void *value, llist_t *llist)
{
	node_t *new = node_create(key, value);
	node_t *tmp = llist->first;

	if (!new)
		return (NULL);
	llist->size++;
	if (!tmp) {
		llist->first = new;
		return (new);
	}
	for (; tmp->next; tmp = tmp->next);
	tmp->next = new;
	new->prev = tmp;
	return (new);
}