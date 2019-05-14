/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_missing_args_for_key_word(const key_word_t *keys, int index,
	char **args, int j)
{
	if (!args || !args[0]) {
		my_printf("WARNING: MALLOC FAILED FOR WORD TAB !\n");
		return (84);
	}
	if (!args[1]) {
		my_printf("WARNING: KEY WORD '%s'", keys[index].key_word);
		my_printf(" MUST HAVE ARGUMENT AFTER '=' !\n");
		return (84);
	}
	if (j == 0 || keys[index].nb_sub_keywords == 0)
		return (0);
	if (my_fastcmp(args[0], keys[index].args[j - 1]) != 0) {
		my_printf("WARNING: EXPECTED SUB KEYWORD '%s'",
		keys[index].args[j - 1]);
		my_printf(" FOR THE KEYWORD '%s' BUT GOT '%s' INSTEAD !\n",
		keys[index].key_word, args[0]);
		return (84);
	}
	return (0);
}

int check_missing_or_invalid_sub_keyword(const key_word_t *keys, int index,
	char **subwords_tab)
{
	int i = 0;
	char **key_args;

	for (; subwords_tab[i]; i++);
	if (i - 1 != keys[index].nb_sub_keywords) {
		my_printf("WARNING: %d ARGUMENT(S) FOR KEYWORD '%s'",
		keys[index].nb_sub_keywords, keys[index].key_word);
		my_printf(" ARE REQUIRED BUT GOT %d !\n", i - 1);
		return (84);
	}
	for (int j = 0; subwords_tab[j]; j++) {
		key_args = my_str_to_word_array(subwords_tab[j],
			KEYWORD_SEPARATOR_CHAR);
		if (check_missing_args_for_key_word(keys, index,
			key_args, j) != 0)
			return (84);
		my_destroy_tab(key_args);
	}
	return (0);
}
