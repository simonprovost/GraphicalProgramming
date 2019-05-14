/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void move_rect(obj_t *obj)
{
	if (obj->obj_rect.rect.left < obj->obj_rect.rect_max.x) {
		obj->obj_rect.rect.left += obj->obj_rect.rect_offset.x;
	}
	if (obj->obj_rect.rect.left >= obj->obj_rect.rect_max.x) {
		obj->obj_rect.rect.left = obj->obj_rect.rect_start.x;
	}
	if (obj->obj_rect.rect.top < obj->obj_rect.rect_max.y) {
		obj->obj_rect.rect.top += obj->obj_rect.rect_offset.y;
	}
	if (obj->obj_rect.rect.top >= obj->obj_rect.rect_max.y) {
		obj->obj_rect.rect.top = obj->obj_rect.rect_start.y;
	}
	sfRectangleShape_setTextureRect(obj->obj, obj->obj_rect.rect);
}

void time_animation(obj_t *obj, float seconds, window_t *window)
{
	if (obj->obj_rect.animated == sfTrue
	&& window->clocker.seconds >= seconds) {
		move_rect(obj);
		sfClock_restart(window->clocker.clock);
	}
}
