/*
** EPITECH PROJECT, 2017
** linked_list_lib
** File description:
** my_llist_create.c
*/

#include "../../include/my.h"
#include "../../include/llist.h"

node_t *get_node_by_key(char *asked, llist_t *llist)
{
	node_t *tmp = llist->first;

	for (; tmp && my_strcmp(tmp->key, asked) == 1; tmp = tmp->next);
	return (tmp);
}

node_t *get_node_by_place(int asked, llist_t *llist)
{
	node_t *tmp = llist->first;

	if (asked <= 0 || asked > llist->size)
		return (NULL);
	for (int i = 1; tmp && i != asked; tmp = tmp->next)
		i++;
	return (tmp);
}

int llist_len(llist_t *llist)
{
	int len = 0;

	for (node_t *tmp = llist->first; tmp; tmp = tmp->next, len++);
	return (len);
}