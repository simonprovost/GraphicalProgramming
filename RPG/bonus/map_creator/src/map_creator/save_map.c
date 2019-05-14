/*
** EPITECH PROJECT, 2018
** map_creator
** File description:
** save_map
*/

#include "map_editor.h"

void write_header(my_w_t *window, int fd)
{
	write(fd, "### FILE : Fichier d'initialisation de zone. ###\n", 49);
	write(fd, "//Format: INIT_INDICATOR + description (voir .h)\n", 49);
	write(fd, "//Format: \tAREA=nom de la région + ENCOUTER=0 ou 1 ", 52);
	write(fd, "+ X=coord_x + Y=coord_y (voir .h pour x y max)\n", 47);
	write(fd, "//Format: \t\t", 12);
	write(fd, "TILE=DATA + BLOCK=bloque ou pas le passage ", 43);
	write(fd, "+ X=coord_x + Y=coord_y (voir .h pour x y max)\n", 47);
	write(fd, "//Format: \t\t\tTEXTURE=ID texture du tile\n\n", 41);
	write(fd, "-", 1);
	write(fd, ZONE_NAME, my_strlen(ZONE_NAME));
	write(fd, "\n", 1);
}

void save_map(my_w_t *window)
{
	int fd = open(ZONE_FILEPATH, O_RDWR | O_CREAT | O_TRUNC, 0666);

	write_header(window, fd);
	write_areas(window, fd);
	write(fd, "\n### END OF FILE ###\n", 21);
}