/*
** EPITECH PROJECT, 2017
** linked_list_lib
** File description:
** my_llist_create.c
*/

#include <stddef.h>
#include "../../include/my.h"
#include "../../include/llist.h"

void *llist_foreach(void *(*fptr)(), llist_t *llist)
{
	node_t *tmp;
	void *my_errno = NULL;

	if (!llist)
		return (NULL);
	tmp = llist->first;
	for (; tmp; tmp = tmp->next) {
		my_errno = fptr(tmp);
		if (my_errno != NULL)
			return (my_errno);
	}
	return (my_errno);
}

void llist_display(llist_t *llist)
{
	for (node_t *tmp = llist->first; tmp; tmp = tmp->next)
		my_printf("%s\n", tmp->key);
}

void llist_rdisplay(llist_t *llist)
{
	node_t *tmp = llist->first;

	for (; tmp->next; tmp = tmp->next);
	for (; tmp; tmp = tmp->prev)
		my_printf("%s\n", tmp->key);
}