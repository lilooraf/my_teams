/*
** EPITECH PROJECT, 2018
** my_strupcase
** File description:
** mystrupcase
*/

char *my_strupcase(char *str)
{
    int count = 0;

    while (str[count] != '\0') {
        if (str[count] >= 97 && str[count] <= 122)
            str[count] = str[count] - 32;
        else if (str[count] < 97 && str[count] > 122)
            str[count] = str[count];
        count++;
    }
    return (str);
}
