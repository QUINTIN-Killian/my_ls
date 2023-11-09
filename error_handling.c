/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Error handling.
** error_handling
*/

#include "include/my.h"
#include "include/my_ls.h"

int error_opening(char *file_path, struct flags_list *flags, int i)
{
    write(2, "ls: impossible d'accéder à '", 30);
    write(2, file_path, my_strlen(file_path));
    write(2, "' : Aucun fichier ou dossier de ce type", 39);
    if (i < flags->total || flags->dir_name_ind != 0 ||
    flags->file_name_ind != 0)
        my_putchar('\n');
    return 84;
}
