/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** recreation du my_putchar
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
