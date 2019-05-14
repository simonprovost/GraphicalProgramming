/*
** EPITECH PROJECT, 2017
** linked_list_lib
** File description:
** my_llist_create.c
*/

#include "../../include/my.h"
#include "../../include/llist.h"

void destroy_node(node_t *node)
{
	if (node) {
		free(node->key);
		free(node);
	}
}

void destroy_llist(llist_t *llist)
{
	node_t *tmp;

	while (llist->first) {
		tmp = llist->first;
		llist->first = llist->first->next;
		destroy_node(tmp);
		tmp = NULL;
	}
	free(llist);
}