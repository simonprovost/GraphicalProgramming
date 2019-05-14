/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** lobby.c
*/

#include "rpg.h"

int intro_events(window_t *window)
{
	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (window->event.type == sfEvtKeyPressed
		|| window->event.type == sfEvtMouseButtonPressed)
			return (1);
	}
	return (0);
}

int intro_animate(sfRectangleShape *intro, float seconds, window_t *window)
{
	static sfIntRect rect = {0, 0, 640, 320};

	if (window->clocker.seconds >= seconds) {
		sfClock_restart(window->clocker.clock);
		if (rect.left < 8320) {
			rect.left += 640;
		}
		if (rect.left >= 8320) {
			rect.left = 0;
			rect.top += 360;
		}
		if (rect.top >= 2520)
			return (1);
		sfRectangleShape_setTextureRect(intro, rect);
		return (0);
	}
	return (0);
}

int intro_loop(sfRectangleShape *intro, window_t *window)
{
	get_time(&window->clocker);
	if (intro_events(window) != 0)
		return (1);
	if (intro_animate(intro, 0.075, window) != 0) {
		return (1);
	}
	sfRenderWindow_drawRectangleShape(window->window, intro, NULL);
	return (0);
}

int set_intro_values(sfRectangleShape *intro)
{
	sfTexture *txture = sfTexture_createFromFile("textures/intro/intro.png",
	NULL);

	if (!txture)
		return (84);
	sfRectangleShape_setTexture(intro, txture, sfTrue);
	sfRectangleShape_setSize(intro, V2F(640, 360));
	sfRectangleShape_setPosition(intro, V2F(80, 120));
	return (0);
}

int start_intro(window_t *window)
{
	int my_errno = 0;
	sfRectangleShape *intro = sfRectangleShape_create();
	sfMusic *intro_music = sfMusic_createFromFile("sounds/intro_music.ogg");

	if (!intro || set_intro_values(intro) != 0 || !intro_music)
		return (84);
	sfMusic_play(intro_music);
	while (sfRenderWindow_isOpen(window->window)) {
		sfRenderWindow_clear(window->window, sfBlack);
		my_errno = intro_loop(intro, window);
		if (my_errno != 0)
			break;
		sfRenderWindow_display(window->window);
	}
	sfRectangleShape_destroy(intro);
	sfMusic_stop(intro_music);
	sfMusic_destroy(intro_music);
	return (my_errno == 1 ? 0 : 84);
}