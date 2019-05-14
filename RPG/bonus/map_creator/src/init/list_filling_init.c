/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "map_editor.h"

obj_data_t get_obj_data_from_infos(obj_infos_t *obj)
{
	obj_data_t data;

	data.name = obj->name[1];
	data.texture = obj->type[1];
	data.button = my_getnbr(obj->button[1]);
	data.position.x = (float)my_getnbr(obj->x[1]);
	data.position.y = (float)my_getnbr(obj->y[1]);
	return (data);
}

int init_an_obj(char **infos, my_w_t *window, hashmap_t *current_list)
{
	obj_infos_t obj;
	obj_data_t data;

	obj.name = my_str_to_word_array(infos[0], '=');
	obj.type = my_str_to_word_array(infos[1], '=');
	obj.button = my_str_to_word_array(infos[2], '=');
	obj.x = my_str_to_word_array(infos[3], '=');
	obj.y = my_str_to_word_array(infos[4], '=');
	data = get_obj_data_from_infos(&obj);
	if (add_obj_to_list(&data, current_list, window) != 0)
		return (84);
	my_destroy_tab(obj.name);
	my_destroy_tab(obj.type);
	my_destroy_tab(obj.button);
	my_destroy_tab(obj.x);
	my_destroy_tab(obj.y);
	return (0);
}

text_data_t get_text_data_from_infos(text_infos_t *text, my_w_t *window)
{
	text_data_t data;

	data.name = text->name[1];
	data.text = text->text[1];
	my_replace_char(data.text, TEXT_SEPARATOR_CHAR, ' ');
	data.font = hm_get(window->fonts_lib, text->font[1]);
	data.charac_size = my_getnbr(text->charac_size[1]);
	data.position.x = (float)my_getnbr(text->x[1]);
	data.position.y = (float)my_getnbr(text->y[1]);
	return (data);
}

text_infos_t get_text_infos(char **infos)
{
	text_infos_t text;

	text.name = my_str_to_word_array(infos[0], '=');
	text.text = my_str_to_word_array(infos[1], '=');
	text.font = my_str_to_word_array(infos[2], '=');
	text.charac_size = my_str_to_word_array(infos[3], '=');
	text.x = my_str_to_word_array(infos[4], '=');
	text.y = my_str_to_word_array(infos[5], '=');
	return (text);
}

int init_a_text(char **infos, my_w_t *window, hashmap_t *current_list)
{
	text_infos_t text = get_text_infos(infos);
	text_data_t data = get_text_data_from_infos(&text, window);

	if (check_unexisting_font(data.font, text.font[1]) != 0)
		return (84);
	if (add_text_to_list(&data, current_list) != 0)
		return (84);
	return (0);
}
