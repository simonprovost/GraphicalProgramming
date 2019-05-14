/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

double my_rand(double a, double b)
{
	return ((rand() / (double)RAND_MAX) * (b - a) + a);
}
