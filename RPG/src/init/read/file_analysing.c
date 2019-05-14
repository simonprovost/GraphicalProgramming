/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int init_from_pcf(char **infos, game_t *game, const key_word_t *keys)
{
	char **type = my_str_to_word_array(infos[0], KEYWORD_SEPARATOR_CHAR);
	static hashmap_t *current_list;
	unsigned int i = 0;
	int my_errno = 0;

	for (; keys[i].key_word; i++) {
		if (my_fastcmp(keys[i].key_word, type[0]) == 0
		&& check_missing_or_invalid_sub_keyword(keys, i, infos) != 0)
			return (84);
		if (my_fastcmp(keys[i].key_word, type[0]) == 0) {
			my_errno = keys[i].fptr(infos, type,
				&current_list, game);
			break;
		}
	}
	if (check_invalid_key_word(keys[i].key_word, type, infos,
		my_errno) != 0)
		return (84);
	return (0);
}

int get_infos(getline_t *gl, game_t *game, get_infos_t *infos)
{
	char **line_words = NULL;

	while ((gl->read = getline(&gl->line, &gl->len, gl->file)) != -1
	&& my_strlen(gl->line) > 1) {
		line_words = my_str_to_word_array(gl->line,
		DATASET_SEPARATOR_CHAR);
		if (!line_words || !line_words[0])
			return (84);
		if (init_from_pcf(line_words, game, infos->keys) != 0)
			return (84);
		free(gl->line);
		gl->line = NULL;
	}
	return (0);
}

int analyse_pcf(game_t *game, get_infos_t *infos)
{
	getline_t gl = {fopen(infos->filepath, "r"), NULL, 0, 0};
	int my_errno = 0;

	if (check_invalid_file(gl.file, infos->filepath) != 0)
		return (84);
	while ((gl.read = getline(&gl.line, &gl.len, gl.file)) != -1) {
		if (my_fastcmp(gl.line, infos->indicator) == 0) {
			infos->savior(game);
			my_errno = get_infos(&gl, game, infos);
		}
		if (my_errno != 0)
			return (my_errno);
		free(gl.line);
		gl.line = NULL;
	}
	fclose(gl.file);
	return (my_errno);
}
