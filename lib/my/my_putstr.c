/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** creer un string qui affiche des caracteres un par un
*/

void my_putchar(char c);

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}
