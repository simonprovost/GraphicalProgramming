/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#ifndef RPGINIT_H_
#define RPGINIT_H_

///////////////////////////////// INITIALISATION ////////////////////////////

typedef struct key_word_s key_word_t;

typedef struct get_infos_s
{
	char *filepath;
	char *indicator;
	const key_word_t *keys;
	void (*savior)(game_t *);
} get_infos_t;

typedef struct key_word_s
{
	char *key_word;
	int nb_sub_keywords;
	int (*fptr)(char **, char **, hashmap_t **, game_t *);
	char **args;
} key_word_t;

typedef struct text_infos_s
{
	char **name;
	char **text;
	char **font;
	char **charac_size;
	char **x;
	char **y;
} text_infos_t;

typedef struct obj_infos_s
{
	char **name;
	char **type;
	char **button;
	char **x;
	char **y;
} obj_infos_t;

/////////////////////////////////////// DATAS ////////////////////////////////

typedef struct obj_data_s
{
	char *name;
	char *texture;
	sfBool button;
	sfVector2f position;
} obj_data_t;

typedef struct text_data_s
{
	char *name;
	char *text;
	sfFont *font;
	int charac_size;
	sfVector2f position;
} text_data_t;

//////////////////////////////////// DATA HUD /////////////////////////////

typedef struct button_s {
	char **balise;
	int (*instruction)();
} button_t;

#endif /* RPGINIT_H_ */
