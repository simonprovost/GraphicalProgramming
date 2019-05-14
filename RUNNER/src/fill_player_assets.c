/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** null
*/

#include "my_runner.h"

void fill_assets_player(p_assets_t *p)
{
	p->font = sfFont_createFromFile("ressources/Relaway.ttf");
	p->speed_x = 10;
	p->dead = 0;
	p->life = 5;
	p->speed_reactor_up = 25;
	p->speed_reactor_down = 10;
	p->life_sprite = sfSprite_create();
	p->life_texture = sfTexture_createFromFile("ressources/life.png", NULL);
	sfSprite_setTexture(p->life_sprite, p->life_texture, sfTrue);
	sfSprite_setScale(p->life_sprite, (sfVector2f){0.5, 0.5});
	sfSprite_setPosition(p->life_sprite, (sfVector2f){950, 620});
	p->life_player = sfText_create();
	sfText_setFont(p->life_player, p->font);
	sfText_setCharacterSize(p->life_player, 60);
	sfText_setPosition(p->life_player, (sfVector2f){1005, 650});
	sfSprite_setTextureRect(p->life_sprite,
				(sfIntRect){0, 0, 901 / 3, 300});
	p->background_sound = sfMusic_createFromFile(BACK_SONG);
	p->stop_fly = sfMusic_createFromFile("ressources/sound/stop_fly.ogg");
	p->obstacle = sfMusic_createFromFile("ressources/sound/obstacle.ogg");
}
