/*
** EPITECH PROJECT, 2017
** my_prg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

static const button_t g_tab[] =
{
	{(char *[]){"NEW_GAME", NULL}, new_game},
	{(char *[]){"CONTINUE", NULL}, launch_game},
	{(char *[]){"SELECT_VARYAN", NULL}, select_varyan},
	{(char *[]){"SELECT_JAINA", NULL}, select_jaina},
	{(char *[]){"SELECT_AVELUS", NULL}, select_avelus},
	{(char *[]){"OPTION", NULL}, option},
	{(char *[]){"CREDITS", NULL}, credits},
	{(char *[]){"STATS", NULL}, stats},
	{(char *[]){"INVENTORY", NULL}, inventory},
	{(char *[]){"MAP", NULL}, nothing},
	{(char *[]){"PAUSE", NULL}, pause_game},
	{(char *[]){"QUESTS", NULL}, quetes},
	{(char *[]){"QUIT", NULL}, quit},
	{(char *[]){"LOAD", NULL}, reload},
	{(char *[]){"RESUME", NULL}, resume},
	{(char *[]){"SAVE", NULL}, save},
	{(char *[]){"EXIT", NULL}, exit_game},
	{(char *[]){"HOME", NULL}, main_menu},
	{(char *[]){"SONG", NULL}, manage_song},
	{(char *[]){"FRAME_RATE_MORE", NULL}, frame_rate_more},
	{(char *[]){"FRAME_RATE_LESS", NULL}, frame_rate_less},
	{(char *[]){"CONTROL", NULL}, control_key},
	{(char *[]){"KEY_ZQSD", NULL}, key_french},
	{(char *[]){"KEY_WASD", NULL}, key_english},
	{(char *[]){"YES", NULL}, yes_save},
	{(char *[]){"NO", NULL}, no_save},
	{(char *[]){"SPECIAL", NULL}, use_special},
	{(char *[]){"ITEMS", NULL}, nothing},
	{(char *[]){"ATTACK", NULL}, attack},
	{(char *[]){"RUN_AWAY", NULL}, run_away},
	{(char *[]){"END_SCREEN_CROSS", NULL}, end_screen_cross},
	{(char *[]){"LVL_UP_CROSS", NULL}, lvl_up_cross},
	{(char *[]){"HOW_TO_PLAY", NULL}, how_to_play},
	{NULL, NULL}
};

int init_button_callback(bucket_t *button_bucket, game_t *game);

int update_button(char *seek, char *replacement, scene_t *scene, game_t *game)
{
	bucket_t *button_bucket = hm_get_bucket(scene->objs, seek);
	bucket_t *text_bucket = hm_get_bucket(scene->texts, seek);
	sfText *text;

	if (!button_bucket || !text_bucket)
		return (84);
	text = text_bucket->value;
	free(button_bucket->key);
	free(text_bucket->key);
	button_bucket->key = my_strdup(replacement);
	text_bucket->key = my_strdup(replacement);
	if (!button_bucket->key || !text_bucket->key)
		return (84);
	sfText_setString(text, replacement);
	return (init_button_callback(button_bucket, game));
}

int seek_button_type(char **balise, int (*instruction)(),
char *button_key, obj_t *button)
{
	int i = 0;

	for (; balise[i]; i++) {
		if (my_fastcmp(balise[i], button_key) == 0) {
			button->callback = instruction;
			break;
		}
	}
	return (0);
}

int init_button_callback(bucket_t *button_bucket, game_t *game)
{
	obj_t *button = button_bucket->value;
	int my_errno = 0;

	if (!button)
		return (84);
	if (button->button == sfFalse)
		return (0);
	button->callback = NULL;
	for (int i = 0; g_tab[i].balise != 0; i++) {
		my_errno = seek_button_type(g_tab[i].balise,
		g_tab[i].instruction, button_bucket->key, button);
		if (my_errno != 0)
			break;
	}
	if (check_unexisting_button(button->callback, button_bucket->key) != 0)
		return (84);
	(void)game;
	return (my_errno);
}

int read_scenes(bucket_t *scene_bucket, game_t *game)
{
	scene_t *scene = scene_bucket->value;

	if (read_hashmap(NULL, game, scene->objs,
		&init_button_callback) != 0)
		return (84);
	return (0);
}

int init_buttons(game_t *game)
{
	if (read_hashmap(NULL, game, SCENES, &read_scenes) != 0)
		return (84);
	return (0);
}
