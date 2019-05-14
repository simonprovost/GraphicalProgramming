/*
** EPITECH PROJECT, 2018
** Sans titre(Espace de travail)
** File description:
** read_hashmap
*/

#include "map_editor.h"

void check_for_big_texture(bucket_t *tmp, texture_list_t *list)
{
	texture_t *texture = tmp->value;
	sfTexture *texture_sf = texture->texture;

	if (sfTexture_getSize(texture_sf).x > 50
	|| sfTexture_getSize(texture_sf).y > 50)
		add_big_texture_to_list(list, tmp->value);
	else
		add_texture_to_list(list, tmp->value);
}

texture_list_t *read_hashmap_texture(hashmap_t *textures)
{
	texture_list_t *list = malloc(sizeof(*list));
	bucket_t *tmp;

	list->rec = NULL;
	for (unsigned int i = 0; i != textures->size; i++) {
		tmp = textures->data[i];
		while (tmp) {
			check_for_big_texture(tmp, list);
			tmp = tmp->next;
		}
	}
	return (list);
}