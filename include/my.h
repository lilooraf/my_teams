/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef __MY_H__
#define __MY_H__

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>

void my_putchar(char c);

void my_putstr(char *str);

void my_putstr_err(char *str);

int my_putstrn(char *str);

int my_strlen(char *str);

int my_isneg(int nb);

int my_put_nbr(int nb);

int my_isnum(char *str);

int my_put_nbrn(int nb);

int my_getnbr(char *str);

void my_sort_int_array(int *tab, int size);

int my_commute_power_rec(int nb, int power);

int my_compute_square_root(int nb);

int my_is_prime(int nb);

char **my_str_to_word_array(char *, char);

int my_find_prime_sup(int nb);

void my_swap(int *a, int *b);

char *my_strcpy(char *dest, char *src);

char **array_cat(char **, char **);

char *my_strncpy(char *dest, char *src, int n);

char *my_revstr(char *str);

int my_strcmp(char *s1, char *s2);

int my_strncmp(char *s1, char *s2, int n);

char *my_strupcase(char *str);

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str);

int my_str_isalpha(char *str);

int my_str_islower(char *str);

int my_array_height(char **array);

int my_str_isupper(char *str);

int my_str_isprintable(char *str);

int my_showstr(char *str);

int my_showmem(char *str, int size);

char *my_strcat(char *dest, char *src);

char *my_strncat(char *dest, char *src, int nb);

char *my_strdup(char *src);

char *my_putnbr_base(int nb, char *base);

void my_putunsigned_nbr(unsigned int nb);

int my_printf(char *str, ...);

int usage(void);

char *my_clean_string(char *str);

void my_swap_string(char **, char **);

char **my_arraydup(char **);

void *my_calloc(size_t, size_t);

int my_array_height(char **array);

char **my_put_in_alpha(char **);

char **char_from_file(char *);

int get_options(char **param);

char **get_file(void);

char cap_char(char c);

int is_considered(char c, char *str);

char *change_char(char *str, char from, char to, int nbr);

void free_array(char **array);

char *clean_not_considered(char *str, char *others);

char **skip_if_double(char **array);

char **display_coding_sequences(char *str);

char *cl_str(char *st, char c);

char *int_to_str(int nb);

#endif
