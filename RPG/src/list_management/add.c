/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int add_text_to_list(text_data_t *data, hashmap_t *current_list)
{
	sfText *sftext;

	if (check_already_existing_text(data->name, current_list) != 0)
		return (84);
	sftext = sfText_create();
	if (!sftext)
		return (84);
	sfText_setString(sftext, data->text);
	sfText_setFont(sftext, data->font);
	sfText_setCharacterSize(sftext, data->charac_size);
	sfText_setPosition(sftext, data->position);
	hm_add(current_list, data->name, sftext);
	return (0);
}

int add_obj_to_list(obj_data_t *data, hashmap_t *list, game_t *game)
{
	obj_t *new_obj;

	if (check_already_existing_obj(data->name, list) != 0)
		return (84);
	new_obj = create_obj(data, game);
	if (new_obj == NULL)
		return (84);
	hm_add(list, data->name, new_obj);
	return (0);
}

int add_scene_to_display_list(bucket_t *scene, game_t *game)
{
	managed_scene_t *display = create_display(scene->key, scene->value);
	managed_scene_t *tmp = MANAGED_SCENES;

	if (!display)
		return (84);
	start_scene_music(display->scene);
	if (!tmp) {
		MANAGED_SCENES = display;
		return (0);
	}
	if (tmp->scene->priority >= display->scene->priority) {
		display->next = tmp;
		MANAGED_SCENES = display;
		return (0);
	}
	for (; tmp->next && display->scene->priority >
	tmp->next->scene->priority; tmp = tmp->next);
	display->next = tmp->next;
	tmp->next = display;
	return (0);
}

int add_tile_to_list(char *texture, game_t *game)
{
	tile_list_t *display = create_tile(texture, game);
	tile_list_t *tmp = TILE_LIST;

	if (!display)
		return (84);
	if (!tmp) {
		TILE_LIST = display;
		return (0);
	}
	if (tmp->tile->priority >= display->tile->priority) {
		display->next = tmp;
		TILE_LIST = display;
		return (0);
	}
	while (tmp->next
		&& display->tile->priority > tmp->next->tile->priority)
		tmp = tmp->next;
	display->next = tmp->next;
	tmp->next = display;
	return (0);
}
