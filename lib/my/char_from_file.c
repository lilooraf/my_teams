/*
** EPITECH PROJECT, 2019
** char_from_file
** File description:
** char_from_file
*/

#include "../../include/my.h"

char **char_from_file(char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    struct stat sb;
    char **array = NULL;
    char *tmp = my_calloc(sizeof(char), 2);
    char buffer;
    int count;

    stat(file_path, &sb);
    if (fd < 0 || !S_ISREG(sb.st_mode)) {
        close(fd);
        exit(84);
    }
    for (count = 0; read(fd, &buffer, 1); count++) {
        tmp = my_strcat(tmp, &buffer);
        tmp[count + 1] = '\0';
    }
    close(fd);
    array = my_str_to_word_array(tmp, '\n');
    free(tmp);
    return (array);
}
