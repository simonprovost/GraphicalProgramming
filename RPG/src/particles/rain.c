/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** rain.c created: 01/05/18
*/

#include <rpg.h>

particle_sys_t *create_rain_sys(game_t *game)
{
	sfIntRect spawn = (sfIntRect) {.top = 0, .left = 0,
				.height = 2, .width = 800};
	particle_sys_t *sys = create_particle_sys(spawn,
		"RAIN_DROP", 300, game);

	sys->spawn_density = 2;
	sys->force = V2F(0, 4);
	sys->sys_name = "main_rain";
	return (sys);
}

void init_rain(game_t *game)
{
	particle_sys_t *sys = create_rain_sys(game);
	texture_t *tex = hm_get(TEXTURES_LIB, "BG_INTERFACE");
	sfSprite *bg = sfSprite_create();

	if (!tex || !sys || !bg)
		return;
	sfSprite_setTexture(bg, tex->texture, sfFalse);
	sfSprite_setColor(bg, sfColor_fromRGBA(255, 255, 255, 150));
	PARTICLES->rain = sys;
	PARTICLES->rain_background = bg;
	game->particles->rain->activated = false;
}

void rain(game_t *game, window_t *window)
{
	if (!(game->particles->rain) || !(game->particles->rain_background))
		return;
	if (game->particles->rain->activated)
		sfRenderWindow_drawSprite(window->window,
					PARTICLES->rain_background, NULL);
}

void check_rain(game_t *game)
{
	if (ZONE_COOR_X == 4 && ZONE_COOR_Y == 4) {
		PARTICLES->rain->spawned_particles_nbr = 0;
		init_particle_position(PARTICLES->rain);
		game->particles->rain->activated = true;
	} else
		game->particles->rain->activated = false;
}