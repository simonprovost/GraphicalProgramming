/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int get_rect_values(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	texture_t *texture;
	char **left = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	char **top = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);
	char **width = my_str_to_word_array(infos[3], KEYWORD_SEPARATOR_CHAR);
	char **height = my_str_to_word_array(infos[4], KEYWORD_SEPARATOR_CHAR);

	if (check_undefined_texture(CURRENT_BUCKET, infos[0]) != 0)
		return (84);
	texture = CURRENT_BUCKET->value;
	if (!left || !top || !width || !height || !texture)
		return (84);
	texture->rect = (sfIntRect){my_getnbr(left[1]), my_getnbr(top[1]),
		my_getnbr(width[1]), my_getnbr(height[1])};
	my_destroy_tab(left);
	my_destroy_tab(top);
	my_destroy_tab(width);
	my_destroy_tab(height);
	(void)type;
	(void)current_list;
	return (0);
}

int get_rect_max_values(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	texture_t *texture;
	char **x = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	char **y = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);

	if (check_undefined_texture(CURRENT_BUCKET, infos[0]) != 0)
		return (84);
	texture = CURRENT_BUCKET->value;
	if (!texture)
		return (84);
	texture->rect_max = (sfVector2i){my_getnbr(x[1]), my_getnbr(y[1])};
	my_destroy_tab(x);
	my_destroy_tab(y);
	(void)type;
	(void)current_list;
	return (0);
}

int get_rect_start_values(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	texture_t *texture;
	char **x = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	char **y = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);

	if (check_undefined_texture(CURRENT_BUCKET, infos[0]) != 0)
		return (84);
	texture = CURRENT_BUCKET->value;
	if (!texture)
		return (84);
	texture->rect_max = (sfVector2i){my_getnbr(x[1]), my_getnbr(y[1])};
	my_destroy_tab(x);
	my_destroy_tab(y);
	(void)type;
	(void)current_list;
	return (0);
}

int get_rect_max_offset(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	texture_t *texture;
	char **x = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	char **y = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);

	if (check_undefined_texture(CURRENT_BUCKET, infos[0]) != 0)
		return (84);
	texture = CURRENT_BUCKET->value;
	if (!texture)
		return (84);
	texture->rect_offset = (sfVector2i){my_getnbr(x[1]), my_getnbr(y[1])};
	my_destroy_tab(x);
	my_destroy_tab(y);
	(void)type;
	(void)current_list;
	return (0);
}
