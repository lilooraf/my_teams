/*
** EPITECH PROJECT, 2019
** swap string
** File description:
** my_swap_string
*/

void my_swap_string(char **str1, char **str2)
{
    char *tmp = 0;

    tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
}
