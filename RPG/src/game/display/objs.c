/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "rpg.h"

int display_obj(obj_t *obj, window_t *window)
{
	sfRenderWindow_drawRectangleShape(window->window,
		obj->obj, NULL);
	time_animation(obj, CLOCK_SPEED_MENU, window);
	return (0);
}

int seek_bucket_priority(bucket_t *bucket, int priority, window_t *window)
{
	bucket_t *tmp = bucket;
	obj_t *obj;

	while (tmp) {
		obj = tmp->value;
		if (obj->priority == priority)
			display_obj(obj, window);
		tmp = tmp->next;
	}
	return (0);
}

int seek_priority(hashmap_t *objs, int priority, window_t *window)
{
	bucket_t *tmp;

	for (unsigned int i = 0; i != objs->size; i++) {
		tmp = objs->data[i];
		if (seek_bucket_priority(tmp, priority, window) != 0)
			return (84);
	}
	return (0);
}

int display_objs(hashmap_t *objs, window_t *window)
{
	for (int i = 0; i != PRIORITY_MAX; i++)
		if (seek_priority(objs, i, window) != 0)
			return (84);
	return (0);
}
