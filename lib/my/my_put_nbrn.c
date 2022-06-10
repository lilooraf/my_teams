/*
** EPITECH PROJECT, 2018
** my_putnbr
** File description:
** ecrire un chiffre
*/

void my_putchar(char c);

void my_put_nbrn(int nb)
{
    int i;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9) {
        i = (nb % 10);
        nb = (nb / 10);
        my_put_nbrn(nb);
        my_putchar(i + 48);
    }
    else
        my_putchar(nb + 48);
    my_putchar('\n');
}
