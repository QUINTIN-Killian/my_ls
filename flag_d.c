/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** d flag functions.
** flag_d
*/

#include "include/my.h"
#include "include/my_ls.h"

int flag_d(struct flags_list *flags)
{
    for (int i = 0; i < flags->file_name_ind; i++) {
        my_putstr(flags->file_name[i]);
        if (i < flags->file_name_ind - 1 || flags->dir_name_ind > 0)
            my_putstr("  ");
    }
    for (int i = 0; i < flags->dir_name_ind; i++) {
        my_putstr(flags->dir_name[i]);
        if (i < flags->dir_name_ind - 1)
            my_putstr("  ");
    }
    return 0;
}
