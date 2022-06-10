/*
** EPITECH PROJECT, 2019
** my_putstr_err
** File description:
** my_putstr_err
*/

#include <unistd.h>

void my_putstr_err(char *str)
{
    for (int count = 0; str[count] != '\0'; count++)
        write(2, &str[count], 1);
}
