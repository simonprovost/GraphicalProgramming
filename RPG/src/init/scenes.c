/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

scene_t *scene_init(int priority)
{
	scene_t *value = malloc(sizeof(scene_t));

	if (!value)
		return (NULL);
	value->objs = hm_create(64, &obj_destroy);
	if (!value->objs)
		return (NULL);
	value->texts = hm_create(64, &sfText_destroy);
	if (!value->texts)
		return (NULL);
	value->music.music = NULL;
	value->music.loop = 0;
	value->music.play_music = 0;
	value->priority = priority;
	return (value);
}

int init_scene_lists(char **infos, game_t *game)
{
	char **name = my_str_to_word_array(infos[0], KEYWORD_SEPARATOR_CHAR);
	char **priority = my_str_to_word_array(infos[1],
		KEYWORD_SEPARATOR_CHAR);
	bucket_t *scene;
	scene_t *value;

	if (!name || !priority)
		return (84);
	scene = hm_get_bucket(SCENES, name[1]);
	if (check_already_existing_scene(scene, name[1]) != 0)
		return (84);
	value = scene_init(my_getnbr(priority[1]));
	if (!value)
		return (84);
	hm_add(SCENES, name[1], value);
	my_destroy_tab(name);
	my_destroy_tab(priority);
	return (0);
}

int init_scenes(game_t *game)
{
	const key_word_t scene_keys[] = {
	{"SCENE", 1, &get_scene, (char *[]) {"PRIORITY", NULL}},
	{"LIST", 0, &get_list, NULL},
	{"OBJ", 4, &get_obj,
		(char *[]) {"TEXTURE", "BUTTON", "X", "Y", NULL}},
	{"TEXT", 5, &get_text,
		(char *[]) {"STR", "FONT", "CHARAC_SIZE", "X", "Y", NULL}},
	{"MUSIC", 1, &get_music, (char *[]) {"LOOP", NULL}},
	{NULL, 0, NULL, NULL}};
	get_infos_t infos = {"pcf/scenes.pcf", INIT_CHAR, scene_keys,
	&list_savior};

	SCENES = hm_create(16, &scenes_destroy);
	if (!SCENES || analyse_pcf(game, &infos) != 0) {
		my_printf("WARNING: ERROR IN SCENES LIST INIT !\n");
		return (84);
	}
	return (0);
}
