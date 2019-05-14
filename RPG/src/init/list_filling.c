/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void get_obj_data_from_infos(obj_infos_t *obj, obj_data_t *data)
{
	data->name = obj->name[1];
	data->texture = obj->type[1];
	data->button = my_getnbr(obj->button[1]);
	data->position.x = (float)my_getnbr(obj->x[1]);
	data->position.y = (float)my_getnbr(obj->y[1]);
}

int init_an_obj(char **infos, game_t *game, hashmap_t *current_list)
{
	obj_infos_t obj;
	obj_data_t data;

	obj.name = my_str_to_word_array(infos[0], KEYWORD_SEPARATOR_CHAR);
	obj.type = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	obj.button = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);
	obj.x = my_str_to_word_array(infos[3], KEYWORD_SEPARATOR_CHAR);
	obj.y = my_str_to_word_array(infos[4], KEYWORD_SEPARATOR_CHAR);
	get_obj_data_from_infos(&obj, &data);
	if (add_obj_to_list(&data, current_list, game) != 0)
		return (84);
	my_destroy_tab(obj.name);
	my_destroy_tab(obj.type);
	my_destroy_tab(obj.button);
	my_destroy_tab(obj.x);
	my_destroy_tab(obj.y);
	return (0);
}

int get_text_data_from_infos(text_infos_t *text,
text_data_t *data, game_t *game)
{
	data->name = text->name[1];
	data->text = text->text[1];
	my_replace_char(data->text, TEXT_SEPARATOR_CHAR, ' ');
	data->font = hm_get(FONTS_LIB, text->font[1]);
	if (check_unexisting_font(data->font, text->font[1]) != 0)
		return (84);
	data->charac_size = my_getnbr(text->charac_size[1]);
	data->position.x = (float)my_getnbr(text->x[1]);
	data->position.y = (float)my_getnbr(text->y[1]);
	return (0);
}

int get_text_infos(char **infos, text_infos_t *text)
{
	text->name = my_str_to_word_array(infos[0], KEYWORD_SEPARATOR_CHAR);
	text->text = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	text->font = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);
	text->charac_size = my_str_to_word_array(infos[3],
	KEYWORD_SEPARATOR_CHAR);
	text->x = my_str_to_word_array(infos[4], KEYWORD_SEPARATOR_CHAR);
	text->y = my_str_to_word_array(infos[5], KEYWORD_SEPARATOR_CHAR);
	if (!text->name || !text->text || !text->font
	|| !text->charac_size || !text->x || !text->y)
		return (84);
	return (0);
}

int init_a_text(char **infos, game_t *game, hashmap_t *current_list)
{
	text_infos_t text;
	text_data_t data;

	if (get_text_infos(infos, &text) != 0)
		return (84);
	if (get_text_data_from_infos(&text, &data, game) != 0)
		return (84);
	if (check_unexisting_font(data.font, text.font[1]) != 0)
		return (84);
	if (add_text_to_list(&data, current_list) != 0)
		return (84);
	return (0);
}
