/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** null
*/

#include "my_runner.h"

game_object_t *create_object(const char *path_to_spritesheet,
			     sfVector2f pos, sfIntRect rect) {
	game_object_t *object = NULL;
	object = malloc(sizeof(game_object_t));
	object->my_texture = sfTexture_createFromFile(path_to_spritesheet,
						      NULL);
	object->my_sprite = sfSprite_create();
	sfSprite_setTexture(object->my_sprite, object->my_texture, sfTrue);
	object->my_pos = pos;
	object->my_rect = rect;
	sfSprite_setPosition(object->my_sprite, object->my_pos);
	sfSprite_setTextureRect(object->my_sprite, object->my_rect);
	return (object);
}