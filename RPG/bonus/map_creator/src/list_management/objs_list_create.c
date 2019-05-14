/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** null
*/

#include "map_editor.h"

void create_obj_rect(obj_t *new_obj, texture_t *texture)
{
	new_obj->obj_rect.animated = texture->animated;
	new_obj->obj_rect.rect = texture->rect;
	new_obj->obj_rect.rect_start = texture->rect_start;
	new_obj->obj_rect.rect_max = texture->rect_max;
	new_obj->obj_rect.rect_offset = texture->rect_offset;
	sfRectangleShape_setTextureRect(new_obj->obj, texture->rect);
}

obj_t *create_obj(obj_data_t *data, my_w_t *window)
{
	texture_t *texture = hm_get(window->textures_lib, data->texture);
	obj_t *new_obj = malloc(sizeof(obj_t));
	sfVector2f rec_size;

	if (check_unexisting_texture(texture, data->texture) != 0
	|| new_obj == NULL)
		return (NULL);
	new_obj->priority = texture->priority;
	rec_size.x = texture->rect.width;
	rec_size.y = texture->rect.height;
	new_obj->obj = sfRectangleShape_create();
	if (!new_obj->obj)
		return (NULL);
	new_obj->button = data->button % 2;
	sfRectangleShape_setTexture(new_obj->obj, texture->texture, sfTrue);
	sfRectangleShape_setSize(new_obj->obj, rec_size);
	sfRectangleShape_setPosition(new_obj->obj, data->position);
	create_obj_rect(new_obj, texture);
	new_obj->callback = NULL;
	return (new_obj);
}

display_list_t *create_a_display(char *name, scene_t *scene)
{
	display_list_t *display = malloc(sizeof(display_list_t));

	if (!display)
		return (NULL);
	display->scene = scene;
	display->scene_name = name;
	display->next = NULL;
	return (display);
}

tile_list_t *create_a_tile(char *texture_name, my_w_t *window)
{
	tile_list_t *new_tile = malloc(sizeof(tile_list_t));

	if (!new_tile)
		return (NULL);
	new_tile->tile = create_obj(&(obj_data_t){NULL, texture_name, sfFalse,
		(sfVector2f){TILE_COOR_X * WINDOW_PIXELS_UNIT,
			TILE_COOR_Y * WINDOW_PIXELS_UNIT}}, window);
	if (!new_tile->tile)
		return (NULL);
	new_tile->tile->name = my_strdup(texture_name);
	new_tile->next = NULL;
	return (new_tile);
}
