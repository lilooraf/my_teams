/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** my_strncmp
*/

int my_strncmp(char *s1, char *s2, int n)
{
    for (int count = 0; count < n; count++)
        if (s1[count] != s2[count])
            return (s2 - s1);
    return (0);
}
