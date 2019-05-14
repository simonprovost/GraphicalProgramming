/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/

#include "../../include/my.h"

int sum_n_odd_numbers(int n)
{
	int number = 1;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		number = 1;
		for (int j = 0; j < i; j++)
			number += 2;
		sum += number;
	}
	return (sum);
}
