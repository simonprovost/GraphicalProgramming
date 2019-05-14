/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

my_obstacle_t *create_enemy(const char *path,
			    sfVector2f pos, sfIntRect rect, sfVector2f scale) {
	my_obstacle_t *object = NULL;
	object = malloc(sizeof(my_obstacle_t));
	object->my_texture = sfTexture_createFromFile(path, NULL);
	object->my_sprite = sfSprite_create();
	sfSprite_setTexture(object->my_sprite, object->my_texture, sfTrue);
	object->pos = pos;
	object->my_rect = rect;
	sfSprite_setPosition(object->my_sprite, object->pos);
	sfSprite_setScale(object->my_sprite, scale);
	sfSprite_setOrigin(object->my_sprite, (sfVector2f){150, 150});
	return (object);
}
