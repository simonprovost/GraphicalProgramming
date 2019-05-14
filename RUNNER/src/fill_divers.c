/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** null
*/

#include "my_runner.h"

void fill_next_divers(d_t *csfml_object)
{
	sfSprite_setPosition(csfml_object->mission, (sfVector2f){60, -500});
	csfml_object->clock_since_zero = sfClock_create();
	csfml_object->seconds_s_z = 0.0;
	csfml_object->time_since_begin = sfText_create();
	csfml_object->show_second = sfText_create();
	sfText_setCharacterSize(csfml_object->time_since_begin, 60);
	sfText_setCharacterSize(csfml_object->show_second, 60);
	csfml_object->font = sfFont_createFromFile("ressources/font.ttf");
	sfText_setFont(csfml_object->time_since_begin, csfml_object->font);
	sfText_setFont(csfml_object->show_second, csfml_object->font);
	sfText_setPosition(csfml_object->time_since_begin, (sfVector2f){10, 0});
	sfText_setPosition(csfml_object->show_second, (sfVector2f){50, 0});
	sfText_setString(csfml_object->show_second, "s.");
}

void fill_divers(d_t *csfml_object)
{
	char *path = ("ressources/attempt.png");
	csfml_object->clock = sfClock_create();
	csfml_object->rect.top = 0;
	csfml_object->rect.left = 0;
	csfml_object->rect.width = 110;
	csfml_object->rect.height = 110;
	csfml_object->window = my_window_create();
	csfml_object->blood_obstacle = sfSprite_create();
	csfml_object->blood = sfTexture_createFromFile("ressources/blood.png",
						       NULL);
	csfml_object->mission = sfSprite_create();
	csfml_object->texture_mission = sfTexture_createFromFile(path,
								 NULL);
	sfSprite_setTexture(csfml_object->blood_obstacle, csfml_object->blood,
			    sfTrue);
	sfSprite_setPosition(csfml_object->blood_obstacle, BLOOD_RECT);
	sfSprite_setTexture(csfml_object->mission,
			    csfml_object->texture_mission,
			    sfTrue);
	fill_next_divers(csfml_object);
}