/*
** EPITECH PROJECT, 2018
** my_putunsigned_nbr
** File description:
** unsigned int
*/

void my_putchar(char c);

void my_putunsigned_nbr(unsigned int nb)
{
    int i;

    if (nb > 9) {
        i = (nb % 10);
        nb = (nb / 10);
        my_putunsigned_nbr(nb);
        my_putchar(i + 48);
    }
    else
        my_putchar(nb + 48);
}
