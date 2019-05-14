/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "map_editor.h"

void scenes_destroy(scene_t *scene)
{
	hm_destroy(scene->texts);
	hm_destroy(scene->objs);
}

void obj_destroy(obj_t *obj)
{
	sfRectangleShape_destroy(obj->obj);
}

void texture_destroy(texture_t *texture)
{
	sfTexture_destroy(texture->texture);
}

void destroy_and_free(my_w_t *window)
{
	clean_displayed_scenes(window);
	hm_destroy(window->textures_lib);
	hm_destroy(window->audio_lib);
	hm_destroy(window->fonts_lib);
	hm_destroy(window->scenes);
	sfClock_destroy(window->clocker.clock);
	sfRenderWindow_destroy(window->window);
}
