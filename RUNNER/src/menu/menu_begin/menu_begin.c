/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

void handle_loop_main(menu_t *all, int *a)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
		sfSprite_setTexture(all->play_sprite, all->play_sprite_touch,
				    sfTrue);
		sfSprite_setTexture(all->exit, all->exit_texture, sfTrue);
		*a = 1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
		sfSprite_setTexture(all->play_sprite, all->play_sprite_texture,
				    sfTrue);
		sfSprite_setTexture(all->exit, all->exit_touch, sfTrue);
		*a = 0;
	}
}

void pre_fill(menu_t *all)
{
	all->background = sfSprite_create();
	all->back = sfTexture_createFromFile(BACKGROUND_MENU, NULL);
	all->play_sprite = sfSprite_create();
	all->play_sprite_texture = sfTexture_createFromFile(SPRITE_T, NULL);
	all->exit = sfSprite_create();
	all->exit_texture = sfTexture_createFromFile(SPRITE_T_TWO, NULL);
	all->exit_touch = sfTexture_createFromFile(EXIT_BUTTON, NULL);
	all->play_sprite_touch = sfTexture_createFromFile(SPRITE_T_THREE, NULL);
	sfSprite_setTexture(all->background, all->back, sfTrue);
	sfSprite_setTexture(all->play_sprite, all->play_sprite_texture, sfTrue);
	sfSprite_setTexture(all->exit, all->exit_texture, sfTrue);
	sfSprite_setPosition(all->play_sprite, (sfVector2f){250, 400});
	sfSprite_setPosition(all->exit, (sfVector2f){630, 370});
	sfSprite_setScale(all->exit, (sfVector2f){0.5, 0.5});
}

int menu_begin(menu_t *menu)
{
	int a = 0;
	menu_t *all = malloc(sizeof(menu_t));
	sfEvent event;
	sfRenderWindow *window = my_window_create();

	pre_fill(all);
	while (sfRenderWindow_isOpen(window)) {
		menu->play = a;
		if (poll_event_finish(event, window) == 1) {
			sfRenderWindow_setVisible(window, sfFalse);
			return (a);
		}
		sfRenderWindow_clear(window, sfWhite);
		handle_loop_main(all, &a);
		sfRenderWindow_drawSprite(window, all->background, NULL);
		sfRenderWindow_drawSprite(window, all->play_sprite, NULL);
		sfRenderWindow_drawSprite(window, all->exit, NULL);
		sfRenderWindow_display(window);
	}
	sfRenderWindow_setVisible(window, sfFalse);
	return (a);
}