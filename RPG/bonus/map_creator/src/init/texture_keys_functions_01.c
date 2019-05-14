/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "map_editor.h"

int get_a_texture(char **infos, char **type,
	hashmap_t **current_list, my_w_t *window)
{
	texture_t *texture = malloc(sizeof(texture_t));

	if (!texture)
		return (84);
	*current_list = window->textures_lib;
	if (check_already_existing_texture(*current_list, type[1]) != 0)
		return (84);
	texture->texture = NULL;
	texture->animated = sfFalse;
	texture->rect = (sfIntRect){0, 0, 0, 0};
	texture->rect_start = (sfVector2i){0, 0};
	texture->rect_max = (sfVector2i){0, 0};
	texture->rect_offset = (sfVector2i){0, 0};
	texture->name = my_strdup(type[1]);
	hm_add(*current_list, type[1], texture);
	window->current = hm_get_bucket(*current_list, type[1]);
	(void)infos;
	return (0);
}

int get_a_texture_filepath(char **infos, char **type,
	hashmap_t **current_list, my_w_t *window)
{
	texture_t *texture;

	if (check_undefined_texture(window->current, type[0]) != 0)
		return (84);
	texture = window->current->value;
	texture->texture = sfTexture_createFromFile(type[1], NULL);
	if (!texture->texture)
		return (84);
	(void)infos;
	(void)current_list;
	return (0);
}

int get_an_animated(char **infos, char **type,
	hashmap_t **current_list, my_w_t *window)
{
	texture_t *texture;
	sfBool animated;

	if (check_undefined_texture(window->current, type[0]) != 0)
		return (84);
	texture = window->current->value;
	animated = my_getnbr(type[1]);
	if (check_invalid_animated(animated) != 0)
		return (84);
	texture->animated = animated;
	(void)infos;
	(void)current_list;
	return (0);
}

int get_a_priority(char **infos, char **type,
	hashmap_t **current_list, my_w_t *window)
{
	texture_t *texture;
	int priority;

	if (check_undefined_texture(window->current, type[0]) != 0)
		return (84);
	texture = window->current->value;
	priority = my_getnbr(type[1]);
	if (check_invalid_priority(priority, window->current->key) != 0)
		return (84);
	texture->priority = priority;
	(void)infos;
	(void)current_list;
	return (0);
}
