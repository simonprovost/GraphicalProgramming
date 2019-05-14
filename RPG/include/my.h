/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** all prototypes
*/

#ifndef MY_H_
#define MY_H_
#ifndef READ_SIZE
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <wait.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <errno.h>
#include <stddef.h>

#define READ_SIZE 80

void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_put_ull(unsigned long long);
void my_put_llnbr(long long int);
void my_putnbr_base(unsigned long long, char *);
int my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char const *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char *my_int_to_array(int);
char **my_str_to_word_array(char *, char);
int my_fastcmp(char const *, char const *);
char *my_strdup(char *);
char *my_get_next_line(int);
int sum_n_odd_numbers(int);
int sum_n_even_numbers(int);
void my_destroy_tab(char **tab);
char *int_to_str(int nb);
void my_replace_char(char *str, char seeked, char replacement);
char *my_get_filename(char *filepath);
int my_arraycmp(unsigned int *arr1, unsigned int *arr2);
char *my_cleanstr(char *str, char to_clean);
void my_puttab(char *option, char **str);

/* MY_PRINTF */

int my_printf(char *, ...);
void my_printunsignedint(va_list);
void my_printchar(va_list);
void my_printint(va_list);
void my_printstr(va_list);
void my_printlowhexa(va_list);
void my_printuphexa(va_list);
void my_printbinary(va_list);
void my_printadress(va_list);
void my_printoctal(va_list);
void my_printpercent(va_list);
void my_printformatedstring(va_list);
int my_tab_len(const char **);
int my_str_isalphanum(char *str);
int my_find_char(char seeked, char *inside);
void my_replace_char(char *str, char seeked, char replacement);

typedef struct fnct_s
{
	char balise;
	void (*fptr)(va_list list);
} fnct_t;

typedef struct getline_s
{
	FILE *file;
	char *line;
	size_t len;
	int read;
} getline_t;

/////////////////////// CSFML ////////////////////////:

typedef struct framebuffer_s
{
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
} framebuffer_t;

void place_a_square(sfVector2f *size, sfVector2f *pos,
sfRenderWindow *window, sfColor *color);

//////////////////////////////////// DEFINES //////////////////////

#define CHAR_IS_NUM(x) (x >= '0' && x <= '9')
#define CHAR_IS_ALPHA(x) ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))

#endif /* !READ_SIZE */
#endif /* MY_H_ */
