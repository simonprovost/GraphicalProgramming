/*
** EPITECH PROJECT, 2017
** my_swap
** File description:
** swaps the content of two int with adresses as parameter
*/

void my_swap(int *a, int *b)
{
	int c = 0;

	c = *a;
	*a = *b;
	*b = c;
}
