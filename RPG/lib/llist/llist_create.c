/*
** EPITECH PROJECT, 2017
** linked_list_lib
** File description:
** my_llist_create.c
*/

#include "../../include/my.h"
#include "../../include/llist.h"

linked_list_t llist_create(void)
{
	return ((llist_t){0, NULL});
}

node_t *node_create(char *key, void *value)
{
	node_t *new = malloc(sizeof(node_t));

	if (!new)
		return (NULL);
	new->key = my_strdup(key);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}