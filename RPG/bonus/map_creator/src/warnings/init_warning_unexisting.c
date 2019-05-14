/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "map_editor.h"

int check_unexisting_scene(bucket_t *scene, char *asked_scene)
{
	if (!scene) {
		my_printf("WARNING: CAN'T FIND SCENE '%s' !\n",
		asked_scene);
		return (84);
	}
	return (0);
}

int check_unexisting_texture(texture_t *texture, char *texture_name)
{
	if (!texture) {
		my_printf("WARNING: CAN'T FIND TEXTURE '%s' IN TEXTURE LIB !\n",
		texture_name);
		return (84);
	}
	return (0);
}

int check_unexisting_font(sfFont *font, char *font_name)
{
	if (!font) {
		my_printf("WARNING: CAN'T FIND FONT '%s' IN FONT LIB !\n",
		font_name);
		return (84);
	}
	return (0);
}

int check_unexisting_music(sfMusic *music, char *music_name)
{
	if (!music) {
		my_printf("WARNING: CAN'T FIND MUSIC '%s' AT INITIALISATION",
		music_name);
		my_printf(" !\n");
		return (84);
	}
	return (0);
}

int check_unexisting_zone(char *zone_name)
{
	if (!zone_name) {
		my_printf("WARNING: YOU TRIED TO ENTER AN UNEXISTING ZONE !\n");
		return (84);
	}
	return (0);
}
