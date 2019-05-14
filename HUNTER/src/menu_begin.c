/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

int choose_difficulty_game(int a)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp))
		a = 1;
	else if (sfKeyboard_isKeyPressed(sfKeyDown))
		a = 0;
	return (a);
}

int poll_event_finish(sfEvent event, sfRenderWindow *window)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
        	if (event.type == sfEvtClosed)
                	exit (0);
		if (sfKeyboard_isKeyPressed(sfKeyReturn))
			return (1);
        }
	return (0);
}

void fill_my_elem(b_t_t *t, b_tt_t *tt, b_s_t *s, sfFont *font)
{
	init_begin_text(t);
	init_sprite(s);
	init_texture(tt);
	fill_object(t, font);
	init_begin(s, t, tt);
}

int menu_begin_assets(sfRenderWindow *window)
{
	int a = 0;
	b_t_t text;
	b_tt_t texture;
	b_s_t sprite;

	sfEvent event;
	sfFont *font = sfFont_createFromFile("resources/my_font.ttf");
	fill_my_elem(&text, &texture, &sprite, font);
	while (sfRenderWindow_isOpen(window)) {
		if (poll_event_finish(event, window) == 1)
			return (a);
		a = choose_difficulty_game(a);
		display_window_begin(window, a, &text, &sprite);
	}
	return (a);
}

int menu_begin(sfRenderWindow *window)
{
	double a = 0;

	a = menu_begin_assets(window);
	sfRenderWindow_setVisible(window, sfFalse);
	return (a);
}
