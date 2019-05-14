/*
** EPITECH PROJECT, 2017
** sort int array
** File description:
** sort array
*/

void my_swap(int *a, int *b);
int my_put_nbr(int nb);

int exchange(int *tab, int j)
{
	if (tab[j] > tab[j + 1])
		my_swap(&tab[j], &tab[j + 1]);
}

void my_sort_int_array(int *tab, int size)
{
	int i = size - 1;
	int j = 0;

	while (i > 0) {
		while (j < i) {
			exchange(tab, j);
			j = j + 1;
		}
		j = 0;
		i = i - 1;
	}
}
