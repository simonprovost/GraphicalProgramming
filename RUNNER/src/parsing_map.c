/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

char *map_read(char *path)
{
	int fd = fs_open_file(path);
	char *buffer = malloc(sizeof(char) * MAX_SIZE + 1);
	int ready_byte = 0;

	ready_byte = (int) read(fd, buffer, MAX_SIZE);
	buffer[ready_byte] = '\0';
	return (buffer);
}

int get_count_of_enemy(public_class_t *all)
{
	int count = 0;

	for (int i = 0; all->var->map[i] != '\0'; i++) {
		if (all->var->map[i] == 'X')
			count++;
	}
	return (count);
}

void manage_map(public_class_t *all)
{
	int y = 0;
	int j = 0;
	int number_of_enemy = get_count_of_enemy(all);
	all->var->stock_enemy = malloc(sizeof(int *) * number_of_enemy);

	for (int i = 0; i < number_of_enemy; i++)
		all->var->stock_enemy[i] = malloc(sizeof(int) * 2);
	for (int i = 0; all->var->map[i] != '\0'; i++) {
		if (all->var->map[i] == '\n')
			y++;
		if (all->var->map[i] == 'X') {
			all->var->stock_enemy[j][0] = i;
			all->var->stock_enemy[j][1] = y;
			j++;
		}
	}
	all->var->number_of_enemy = number_of_enemy;
}
//TODO A FREE OBLIGATOIRE
//        free(all->var->stock_enemy[0]);
//        free(all->var->stock_enemy[1]);
//        free(all->var->stock_enemy[2]);
//        free(all->var->stock_enemy[3]);
//        free(all->var->stock_enemy[4]);
//        free(all->var->stock_enemy);