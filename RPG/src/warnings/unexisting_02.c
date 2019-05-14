/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_unexisting_text(bucket_t *text, char *asked_text, char *scene_name)
{
	if (!text) {
		my_printf("WARNING: CAN'T FIND TEXT '%s' IN SCENE '%s' !\n",
		asked_text, scene_name);
		return (84);
	}
	return (0);
}

int check_unexisting_obj(bucket_t *obj, char *asked_obj, char *scene_name)
{
	if (!obj) {
		my_printf("WARNING: CAN'T FIND OBJ '%s' IN SCENE '%s' !\n",
		asked_obj, scene_name);
		return (84);
	}
	return (0);
}

int check_unexisting_button(int (*callback)(), char *button_name)
{
	if (!callback) {
		my_printf("WARNING: CAN'T FIND BUTTON '%s' !\n",
		button_name);
		return (84);
	}
	return (0);
}

int check_unexisting_item(item_t *item, char *name)
{
	if (!item) {
		my_printf("WARNING: CAN'T FIND ITEM '%s' !\n", name);
		return (84);
	}
	return (0);
}