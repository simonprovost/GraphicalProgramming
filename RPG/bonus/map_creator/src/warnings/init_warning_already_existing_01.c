/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "map_editor.h"

int check_already_existing_obj(char *obj_name, hashmap_t *current_list)
{
	bucket_t *obj = hm_get_bucket(current_list, obj_name);

	if (obj != NULL) {
		my_printf("WARNING: OBJ '%s' REDECLARED IN SCENE !\n",
		obj_name);
		return (84);
	}
	return (0);
}
int check_already_existing_text(char *text_name, hashmap_t *current_list)
{
	bucket_t *obj = hm_get_bucket(current_list, text_name);

	if (obj != NULL) {
		my_printf("WARNING: TEXT '%s' REDECLARED IN SCENE !\n",
		text_name);
		return (84);
	}
	return (0);
}

int check_already_existing_texture(hashmap_t *hashmap, char *texture_name)
{
	texture_t *texture = hm_get(hashmap, texture_name);

	if (texture != NULL) {
		my_printf("WARNING: TEXTURE '%s' REDECLARED IN TEXTURES !\n",
		texture_name);
		return (84);
	}
	return (0);
}

int check_already_existing_audio(sfMusic *audio, char *audio_name)
{
	if (audio != NULL) {
		my_printf("WARNING: AUDIO '%s' REDECLARED IN SOUNDS !\n",
		audio_name);
		return (84);
	}
	return (0);
}

int check_already_existing_font(sfFont *font, char *font_name)
{
	if (font != NULL) {
		my_printf("WARNING: FONT '%s' REDECLARED IN FONTS !\n",
		font_name);
		return (84);
	}
	return (0);
}
