/*
** EPITECH PROJECT, 2017
** llist.h
** File description:
** all prototypes of linked list lib
*/

#ifndef LLIST_H_
#define LLIST_H_

////////////////////////////// STRUCTURES ///////////////////////////////////

typedef struct node_s node_t;

typedef struct node_s
{
	char *key;
	void *value;
	node_t *next;
	node_t *prev;
} node_t;

typedef struct linked_list_s
{
	unsigned int size;
	node_t *first;
} linked_list_t, llist_t;

////////////////////////////// FUNCTIONS ///////////////////////////////////

////////////////// CREATE

///Create and return an empty llist;
linked_list_t llist_create(void);

///Create and return a node with given key and value. Return NULL on fail.
node_t *node_create(char *key, void *value);

////////////////// ADD

///Create and add to a given llist a node with given key and value.
///Return NULL if an error occured. Else return created node.
node_t *add_to_llist(char *key, void *value, llist_t *llist);

////////////////// GET

///Seek in a given llist a node with the given key and return the node or NULL
///if not found.
node_t *get_node_by_key(char *asked, llist_t *llist);

///Seek in a given llist a node a the given place. If asked <= 0 or
///Asked > number of node in list, return NULL. Else, return the node.
node_t *get_node_by_place(int asked, llist_t *llist);

///return the len of the passed llist;
int llist_len(llist_t *llist);

////////////////// PROCESS

///Send every node in a given list to a given function. If the given function
///return anything else than NULL, return it.
void *llist_foreach(void *(*fptr)(), llist_t *llist);

///Print every node key in a given list.
void llist_display(llist_t *llist);

///Print every node key in a given list from last to first
void llist_rdisplay(llist_t *llist);

////////////////// REMOVE

///Seek and remove a node with the passed key in the passed list.
void remove_node_by_key(char *asked, llist_t *llist);

///Seek and remove a node at the passed place in the passed list.
void remove_node_by_place(int place, llist_t *llist);

////////////////// DESTROY

///Free the passed node and his key
void destroy_node(node_t *node);

///free the passed llist and all its nodes.
void destroy_llist(llist_t *llist);

#endif /* LLIST_H_ */