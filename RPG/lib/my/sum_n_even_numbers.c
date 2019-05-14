/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/

#include "../../include/my.h"

int sum_n_even_numbers(int n)
{
	int number = 0;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		number = 0;
		for (int j = 0; j < i; j++)
			number += 2;
		sum += number;
	}
	return (sum);
}
