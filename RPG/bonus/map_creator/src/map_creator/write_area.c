/*
** EPITECH PROJECT, 2018
** map_creator
** File description:
** write_area
*/

#include "map_editor.h"

void write_textures(my_w_t *window, int fd)
{
	char *name = NULL;

	while (TILE.displayed_tiles) {
		name = TILE.displayed_tiles->tile->name;
		write(fd, "\t\t\tTEXTURE=", 11);
		write(fd, name, my_strlen(name));
		write(fd, "\n", 1);
		TILE.displayed_tiles = TILE.displayed_tiles->next;
	}
}

void write_tiles(my_w_t *window, int fd)
{
	char *x = NULL;
	char *y = NULL;

	for (TILE_COOR_Y = 0; TILE_COOR_Y < TILE_TAB_Y; TILE_COOR_Y++) {
		for (TILE_COOR_X = 0; TILE_COOR_X < TILE_TAB_X; TILE_COOR_X++) {
			x = int_to_str(TILE_COOR_X);
			y = int_to_str(TILE_COOR_Y);
			write(fd, "\t\tTILE=DATA BLOCK=", 18);
			write(fd, (TILE_BLOCK ? "1 X=" : "0 X="), 4);
			write(fd, x, my_strlen(x));
			write(fd, " Y=", 3);
			write(fd, y, my_strlen(y));
			write(fd, "\n", 1);
			write_textures(window, fd);
		}
	}
}

void write_area(my_w_t *window, int fd)
{
	char *x = int_to_str(AREA_COOR_X);
	char *y = int_to_str(AREA_COOR_Y);

	if (!AREA.name)
		return;
	write(fd, "\tAREA=", 6);
	write(fd, AREA.name, my_strlen(AREA.name));
	write(fd, " ENCOUNTER=", 11);
	write(fd, "0 X=", 4);
	write(fd, x, my_strlen(x));
	write(fd, " Y=", 3);
	write(fd, y, my_strlen(y));
	write(fd, "\n", 1);
	write_tiles(window, fd);
}

void write_areas(my_w_t *window, int fd)
{
	for (AREA_COOR_Y = 0; AREA_COOR_Y < AREA_TAB_Y; AREA_COOR_Y++) {
		for (AREA_COOR_X = 0; AREA_COOR_X < AREA_TAB_X; AREA_COOR_X++)
			write_area(window, fd);
	}
}