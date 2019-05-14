/*
** EPITECH PROJECT, 2017
** my strncmp
** File description:
** strncmp function
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
	for (int i = 0; i < n; i++) {
		if (s1[i] != s2[i]) {
			return (1);
		}
	}
	return (0);
}
