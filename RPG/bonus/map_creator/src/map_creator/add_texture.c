/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** add_texture
*/

#include "map_editor.h"

void assign_texture_to_elem(texture_list_t *list, sfTexture *texture,
							v2f pos, char *name)
{
	list->texture = texture;
	list->rec = sfRectangleShape_create();
	sfRectangleShape_setTexture(list->rec, texture, sfTrue);
	sfRectangleShape_setSize(list->rec, V2F(50, 50));
	sfRectangleShape_setTextureRect(list->rec, (sfIntRect){0, 0, 50, 50});
	sfRectangleShape_setPosition(list->rec, pos);
	list->pos = pos;
	list->name = name;
	list->next = NULL;
}

void add_texture_to_list(texture_list_t *list, texture_t *texture)
{
	static int a = 0;
	static int b = 0;
	texture_list_t *new_elem;

	if (!list->rec) {
		assign_texture_to_elem(list, texture->texture,
					V2F(810 + a, 10 + b), texture->name);
		a += 52;
		return;
	}
	for (; list->next; list = list->next);
	new_elem = malloc(sizeof(*new_elem));
	assign_texture_to_elem(new_elem, texture->texture,
					V2F(810 + a, 10 + b), texture->name);
	list->next = new_elem;
	a += 52;
	if (a >= 52 * 17) {
		a = 0;
		b += 52;
	}
}

void assign_big_texture_to_elem(texture_list_t *list, sfTexture *texture,
							v2f pos, char *name)
{
	list->texture = texture;
	list->rec = sfRectangleShape_create();
	sfRectangleShape_setTexture(list->rec, texture, sfTrue);
	sfRectangleShape_setSize(list->rec, V2F(50, 50));
	sfRectangleShape_setPosition(list->rec, pos);
	list->pos = pos;
	list->name = name;
	list->next = NULL;
}

void add_big_texture_to_list(texture_list_t *list, texture_t *texture)
{
	static int a = 0;
	static int b = 0;
	texture_list_t *new_elem;

	if (!list->rec) {
		assign_big_texture_to_elem(list, texture->texture,
					V2F(10 + a, 650 + b), texture->name);
		a += 104;
		return;
	}
	for (; list->next; list = list->next);
	new_elem = malloc(sizeof(*new_elem));
	assign_big_texture_to_elem(new_elem, texture->texture,
					V2F(10 + a, 650 + b), texture->name);
	list->next = new_elem;
	a += 104;
	if (a >= 104 * 16) {
		a = 0;
		b += 52;
	}
}