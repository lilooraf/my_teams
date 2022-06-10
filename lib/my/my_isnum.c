/*
** EPITECH PROJECT, 2019
** my_isnum
** File description:
** my isnum
*/

int my_isnum(char *str)
{
    int count = 0;

    for (; str[count] != '\0'; count++)
        if ((str[count] < '0' || str[count] > '9'))
            return (84);
    return (0);
}
