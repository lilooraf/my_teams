/*
** EPITECH PROJECT, 2019
** my_calloc
** File description:
** my_calloc
*/

#include "../../include/my.h"

void *my_calloc(size_t em_size, size_t em)
{
    size_t alloc_size = em_size * em;
    void *block = malloc(alloc_size);
    unsigned char *ptr = block;

    for (; alloc_size; alloc_size--)
        *ptr++ = (unsigned char)(0);
    return (block);
}
