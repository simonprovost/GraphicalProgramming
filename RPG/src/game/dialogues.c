/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** random.c
*/

#include "rpg.h"
#include "my.h"

static const char *random_sentence[] = {
	"Hello adventurer !\nWelcome to the village of Pikili\nYou are free to\
 visit. Don't forget the tavern.",
	"I used to be an adventurer like you.\nThen\
 I took and arrow in the knee.",
	"...",
	"What ?",
	"What do you want ?",
	"You look tired.",
	"I don't know..",
	"I love this place!",
	"Hello !",
	NULL,
};

bucket_t **get_dialogue_hud_texts(game_t *game)
{
	scene_t *dialogue_scene = hm_get(SCENES, "DIALOGUE_HUD");
	bucket_t **texts = malloc(sizeof(bucket_t *) * 4);

	if (!dialogue_scene || !texts)
		return (NULL);
	texts[0] = hm_get_bucket(dialogue_scene->texts, "NAME");
	texts[1] = hm_get_bucket(dialogue_scene->texts, "LINE_01");
	texts[2] = hm_get_bucket(dialogue_scene->texts, "LINE_02");
	texts[3] = hm_get_bucket(dialogue_scene->texts, "LINE_03");
	if (!texts[0] || !texts[1] || !texts[2] || !texts[3])
		return (NULL);
	return (texts);
}

int update_nothing_here(game_t *game)
{
	bucket_t **texts = get_dialogue_hud_texts(game);
	char *name = my_strcat(PLAYER_NAME, " :");
	char *line_01 = "Nothing to do here ..";
	char *line_02 = "";

	if (!texts || !name)
		return (84);
	sfText_setString(texts[0]->value, name);
	sfText_setString(texts[1]->value, line_01);
	sfText_setString(texts[2]->value, line_02);
	sfText_setString(texts[3]->value, line_02);
	free(texts);
	free(name);
	return (0);
}

int update_random_pnj_dialogue(char *named, game_t *game)
{
	bucket_t **texts = get_dialogue_hud_texts(game);
	char *name = my_strcat(named, " :");
	const char *line_01 = random_sentence[rand()
						% my_tab_len(random_sentence)];
	char *line_02 = "";

	if (!texts || !name)
		return (84);
	sfText_setString(texts[0]->value, name);
	sfText_setString(texts[1]->value, line_01);
	sfText_setString(texts[2]->value, line_02);
	sfText_setString(texts[3]->value, line_02);
	free(texts);
	free(name);
	return (1);
}

int update_pnj_dialogue(npc_t *npc, game_t *game)
{
	bucket_t **texts = get_dialogue_hud_texts(game);
	char *name = my_strcat(npc->name, " :");

	if (!texts || !name)
		return (84);
	sfText_setString(texts[0]->value, name);
	sfText_setString(texts[1]->value, npc->line_01);
	sfText_setString(texts[2]->value, npc->line_02);
	sfText_setString(texts[3]->value, npc->line_03);
	free(name);
	free(texts);
	return (1);
}

int update_no_place_dialogue(game_t *game)
{
	bucket_t **texts = get_dialogue_hud_texts(game);
	char *name = my_strcat(PLAYER_NAME, " :");
	char *line_01 = "I didn't add any space for my loot ..";
	char *line_02 = "I had to discard it.";
	char *line_03 = "";

	if (!texts || !name)
		return (84);
	sfText_setString(texts[0]->value, name);
	sfText_setString(texts[1]->value, line_01);
	sfText_setString(texts[2]->value, line_02);
	sfText_setString(texts[3]->value, line_03);
	free(texts);
	free(name);
	return (1);
}