/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** daynightcycle.c created: 11/05/18
*/

#include <rpg.h>

int init_day_night_cycle(game_t *game)
{
	texture_t *tex = hm_get(TEXTURES_LIB, "NIGHT");

	if (!tex)
		return (1);
	game->particles->night_color = sfSprite_create();
	if (!game->particles->night_color)
		return (1);
	sfSprite_setTexture(game->particles->night_color,
			tex->texture, sfFalse);
	return (0);
}

sfUint8 get_night_opacity(void)
{
	static sfClock *clock = NULL;
	sfTime time;
	sfUint8 factor = 0;
	static sfBool check = false;

	if (!clock) {
		clock = sfClock_create();
		if (!clock)
			return (0);
	}
	time = sfClock_getElapsedTime(clock);
	factor = (sfUint8) (sin(((double)sfTime_asSeconds(time)) \
	/ 120) * 225);
	if (factor == 0 && check == true) {
		sfClock_restart(clock);
		check = false;
	} else if (factor == 224 && check == false)
		check = true;
	return (factor);
}

void update_day_night_cycle(game_t *game)
{
	sfSprite *sprite = game->particles->night_color;
	sfUint8 factor = 0;

	if (my_strcmp(CURRENT_BUCKET->key, "GAME") != 0)
		return;
	factor = get_night_opacity();
	if (my_strcmp(ZONE_NAME, "TAVERN") == 0
	|| my_strcmp(ZONE_NAME, "INTERIOR") == 0)
		return;
	sfSprite_setColor(sprite, sfColor_fromRGBA(255, 255, 255, factor));
	sfRenderWindow_drawSprite(game->window->window, sprite, NULL);
}
