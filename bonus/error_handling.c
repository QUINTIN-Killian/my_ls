/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Error handling.
** error_handling
*/

#include "include/my.h"
#include "include/my_ls.h"

int error_opening(char *file_path, int *nb_other)
{
    write(2, "ls: ", 4);
    write(2, file_path, my_strlen(file_path));
    write(2, ": No such file or directory", 27);
    *nb_other = *nb_other - 1;
    if (*nb_other >= 0)
        my_putchar('\n');
    return 84;
}
