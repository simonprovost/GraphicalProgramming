/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

float choose_difficulty(float a)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp))
		a = 1;
	else if (sfKeyboard_isKeyPressed(sfKeyDown))
		a = 0;
	return (a);
}

int poll_event_finis(sfEvent event, sfRenderWindow *window)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
        	if (event.type == sfEvtClosed)
                	exit (0);
		if (sfKeyboard_isKeyPressed(sfKeyReturn))
			return (1);
        }
	return (0);
}

float menu_win(sfRenderWindow *window, b_t *var)
{
	fw_t_t t;
	fw_tt_t tt;
	fw_s_t s;
	float a = 0.0;
	sfEvent event;
	sfFont *font = sfFont_createFromFile("resources/my_font.ttf");

	fill_win_elem(&t, &tt, &s);
	init_text_win(font, &t, &s, &tt);
	while (sfRenderWindow_isOpen(window)) {
		if (poll_event_finis(event, window) == 1)
			return (a);
		a = choose_difficulty(a);
		t.a = a;
		display_window_finish_w(window, var, &s, &t);
	}
	return (a);
}

float menu_g_over(sfRenderWindow *window, b_t *var)
{
	f_t_t t;
	f_tt_t tt;
	f_s_t s;
	float a = 0.0;
	sfFont *font = sfFont_createFromFile("resources/my_font.ttf");
	sfEvent event;

	fill_elem_menu(&t, &tt, &s);
	fill_all_elem_menu(&s, &tt);
	init_text_over(font, &t);
	while (sfRenderWindow_isOpen(window)) {
		if (poll_event_finis(event, window) == 1)
			return (a);
		a = choose_difficulty(a);
		t.a = a;
		display_window_finish_over(window, &t, &s, var);
	}
	return (a);
}

float menu(sfRenderWindow *window, b_t *var, int check)
{
	double a = 0;

	if (check == 1) {
		var->finish = sfMusic_createFromFile("resources/you_win.ogg");
		sfMusic_play(var->finish);
		a = menu_win(window, var);
		sfMusic_pause(var->finish);
	} else {
		sfMusic_play(var->finish);
		a = menu_g_over(window, var);
		sfMusic_pause(var->finish);
	}
	sfRenderWindow_setVisible(window, sfFalse);
	return (a);
}
