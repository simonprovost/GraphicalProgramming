/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

void create_obj_rect(obj_t *new_obj, texture_t *texture)
{
	new_obj->obj_rect.animated = texture->animated;
	new_obj->obj_rect.rect = texture->rect;
	new_obj->obj_rect.rect_start = texture->rect_start;
	new_obj->obj_rect.rect_max = texture->rect_max;
	new_obj->obj_rect.rect_offset = texture->rect_offset;
	sfRectangleShape_setTextureRect(new_obj->obj, texture->rect);
}

obj_t *create_obj(obj_data_t *data, game_t *game)
{
	texture_t *texture = hm_get(TEXTURES_LIB, data->texture);
	obj_t *new_obj = malloc(sizeof(obj_t));
	sfVector2f rec_size;

	if (check_unexisting_texture(texture, data->texture) != 0
	|| !new_obj)
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

managed_scene_t *create_display(char *name, scene_t *scene)
{
	managed_scene_t *display = malloc(sizeof(managed_scene_t));

	if (!display)
		return (NULL);
	display->scene = scene;
	display->name = my_strdup(name);
	display->next = NULL;
	return (display);
}

tile_list_t *create_tile(char *texture_name, game_t *game)
{
	tile_list_t *new_tile = malloc(sizeof(tile_list_t));

	if (!new_tile)
		return (NULL);
	new_tile->tile = create_obj(&(obj_data_t){NULL, texture_name, sfFalse,
		(sfVector2f){TILE_COOR_X * WINDOW_PIXELS_UNIT,
			TILE_COOR_Y * WINDOW_PIXELS_UNIT}}, game);
	if (!new_tile->tile)
		return (NULL);
	new_tile->next = NULL;
	return (new_tile);
}

item_t *create_item(char *name, game_t *game)
{
	item_t *new = malloc(sizeof(item_t));
	item_data_t *data = hm_get(ITEMS_LIB, name);

	if (!new || !data || !name)
		return (NULL);
	new->name = my_strdup(data->name);
	new->obj = create_obj(&(obj_data_t){name,
					data->texture, 0, V2F(0, 0)}, game);
	if (!new->obj)
		return (NULL);
	new->quest = data->quest;
	new->consumable = data->consumable;
	new->stats.health = data->stats.health
	+ rand() % (data->stats.health / 2);
	new->stats.armor = data->stats.armor + rand() % (data->stats.armor / 2);
	new->stats.special = data->stats.special
	+ rand() % (data->stats.special / 2);
	new->stats.damages = data->stats.damages;
	return (new);
}