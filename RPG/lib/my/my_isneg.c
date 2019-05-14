/*
** EPITECH PROJECT, 2017
** my_isneg
** File description:
** displays N if the int is negative and P if positive or null
*/

void my_putchar(char);

int my_isneg(int n)
{
	if (n < 0)
		my_putchar('N');
	else
		my_putchar('P');
	my_putchar('\n');
	return (n);
}
