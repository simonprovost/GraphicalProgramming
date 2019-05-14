/*
** EPITECH PROJECT, 2017
** null
** File description:
** null
*/

#include <SFML/Graphics/Rect.h>
#include "my_runner.h"

void move(game_object_t *my_object, int tmp, b_t *var)
{
	(my_object->rect.left >= 7000) ? (my_object->rect.left = 0) : 0;
	my_object->my_rect.top = 0;
	my_object->rect.left += tmp;
	my_object->rect.width = var->width_image;
	my_object->rect.height = var->heigh_image;
	sfSprite_setTextureRect(my_object->my_sprite, my_object->rect);
}
void move_rect(public_class_t *all)
{
	int i = 0;
	int tmp = all->var->speed_parralax;

	while (i != 5) {
		move(all->my_object[0], tmp + 1, all->var);
		move(all->my_object[1], tmp + 2, all->var);
		move(all->my_object[2], tmp + 1, all->var);
		move(all->my_object[3], tmp + 3, all->var);
		move(all->my_object[4], tmp + 2, all->var);
		i++;
	}
}