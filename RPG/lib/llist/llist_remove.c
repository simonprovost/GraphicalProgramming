/*
** EPITECH PROJECT, 2017
** linked_list_lib
** File description:
** my_llist_create.c
*/

#include "../../include/my.h"
#include "../../include/llist.h"

void remove_node_by_key(char *asked, llist_t *llist)
{
	node_t *tmp = llist->first;
	node_t *freed = NULL;

	llist->size--;
	if (tmp && my_strcmp(tmp->key, asked) == 0) {
		llist->first = llist->first->next;
		llist->first->next->prev = llist->first;
		destroy_node(tmp);
		return;
	}
	for (; tmp && tmp->next; tmp = tmp->next) {
		if (my_strcmp(tmp->next->key, asked) == 0)
			break;
	}
	freed = tmp->next;
	tmp->next = tmp->next->next;
	tmp->next->prev = tmp;
	destroy_node(freed);
	return;
}

void remove_node_by_place(int place, llist_t *llist)
{
	node_t *tmp = llist->first;
	node_t *freed = NULL;

	if (place == 1) {
		llist->first = llist->first->next;
		llist->first->next->prev = llist->first;
		destroy_node(tmp);
		return;
	}
	for (int i = 2; tmp && tmp->next; tmp = tmp->next, i++) {
		if (i == place)
			break;
	}
	freed = tmp->next;
	tmp->next = tmp->next->next;
	tmp->next->prev = tmp;
	destroy_node(freed);
	return;
}