/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** null
*/

#include "my_runner.h"

void next_loop_main(public_class_t *all)
{
	check_if_loose(all);
	poll_event(all->csfml_object);
	sfRenderWindow_setMouseCursorVisible(all->csfml_object->window,
	sfFalse);
	assign_w_h(all->var);
	move_rect(all);
	sfSprite_setPosition(all->my_pers[0]->my_sprite,
	all->my_pers[0]->my_pos);
	move_enemy(all);
	manage_player(all);
	collider_level(all);
}

void loop_main(public_class_t *all)
{
	sfRenderWindow_clear(all->csfml_object->window, sfBlack);
	all->csfml_object->time_since_zero = sfClock_getElapsedTime(
		all->csfml_object->clock_since_zero);
	all->csfml_object->seconds_s_z = (float) (
		all->csfml_object->time_since_zero.microseconds / 1000000.00);
	show_second_scale(all);
	check_if_win(all);
	for (int i = 0; i < all->var->number_of_enemy; i++) {
		if (collider_player_enemy(all, i) == sfTrue) {
			collider_box(all->my_pers);
			all->var->check_notify = 1;
		}
	}
	next_loop_main(all);
}

void pre_play(public_class_t *all, char **argv)
{
	manage_before_game(all);
	all->var->map = map_read(argv[1]);
	all->var->size = my_strlen(all->var->map);
	manage_map(all);
	fill_enemy(all);
}

int main(int argc, char *argv[])
{
	menu_t *menu = malloc(sizeof(menu_t));
	public_class_t *all = NULL;
	sfMusic *background_song = sfMusic_createFromFile(PATH_SONG_BACK);

	if (argc == 2 && argv[1][0] != '-' && argv[1][1] != 'h')
	menu->play = menu_begin(menu);
	sfMusic_play(background_song);
	sfMusic_setLoop(background_song, sfTrue);
	if (menu->play == 1 && argc != -1 && argv[1] != NULL) {
		all = malloc(sizeof(public_class_t));
		pre_play(all, argv);
		while (sfRenderWindow_isOpen(all->csfml_object->window)) {
			sfRenderWindow_clear(all->csfml_object->window,
			sfBlack);
			loop_main(all);
			draw_display(all);
		}
		destroy_all(all);
		free(all);
	}
	else
		printf("USAGE --> Add a map in first arg ( my_runner map_0 ).\n");
	return (0);
}