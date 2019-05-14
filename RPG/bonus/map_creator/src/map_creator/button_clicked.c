/*
** EPITECH PROJECT, 2018
** Sans titre(Espace de travail)
** File description:
** button_clicked
*/

#include "map_editor.h"

int button_is_clicked(sfRectangleShape *rec, v2i clickPosition)
{
	v2f pos = sfRectangleShape_getPosition(rec);
	v2f size = sfRectangleShape_getSize(rec);

	return (clickPosition.x < pos.x + size.x &&
	clickPosition.x > pos.x && clickPosition.y < pos.y + size.y &&
	clickPosition.y > pos.y);
}