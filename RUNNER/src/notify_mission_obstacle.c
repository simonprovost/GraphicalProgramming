/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

void next_notify_mission(public_class_t *all, int *i, int *check)
{
	if (*i == -350) {
		*i = -325;
		sfSprite_setPosition(all->csfml_object->mission,
				     (sfVector2f) {270, *i});
		all->var->check_mission = 1;
		*check = 0;
	}
}

void notify_mission(public_class_t *all)
{
	static int check = 0;
	static int i = -300;

	if (all->var->check_mission == 0) {
		if (check == 1) {
			i--;
			next_notify_mission(all, &i, &check);
		} else if (i != -270 && check == 0)
			i++;
		if (i >= -270)
			check =  1;
		sfSprite_setPosition(all->csfml_object->mission,
				     (sfVector2f) {270, i});
	}
}

void next_notif_obstacles(public_class_t *all, int *i, int *check)
{
	if (*i == -350) {
		*i = -325;
		sfSprite_setPosition(all->csfml_object->blood_obstacle,
				     (sfVector2f) {270, *i});
		*check = 0;
		all->var->notify = 0;
		all->var->check_notify = 0;
	}
}

void notify_obstacles(public_class_t *all)
{
	static int check = 0;
	static int i = -300;

	if (all->var->notify == 1) {
		if (check == 1) {
			check = 1;
			i--;
			next_notif_obstacles(all, &i, &check);
			sfSprite_setPosition(all->csfml_object->blood_obstacle,
					     (sfVector2f) {270, i});
		} else if (i != -270 && check == 0) {
			i++;
			sfSprite_setPosition(all->csfml_object->blood_obstacle,
					     (sfVector2f) {270, i});
		}
		if (i >= -270)
			check = 1;
	}
}