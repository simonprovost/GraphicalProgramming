/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_invalid_consumable(sfBool consumable)
{
	if (consumable != sfTrue && consumable != sfFalse) {
		my_printf("WARNING: CONSUMABLE VALUE CAN ONLY BE '0' ");
		my_printf("FOR FALSE OR '1' FOR TRUE !\n");
		return (84);
	}
	return (0);
}
