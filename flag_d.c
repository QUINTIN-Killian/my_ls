/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** contains d flag functions.
** flag_d
*/

#include "include/my.h"
#include "include/my_ls.h"

void d_flag(struct flags_list *flags)
{
    for (int i = 0; i < flags->dir_name_ind; i++) {
        flags->file_name[flags->file_name_ind] = flags->dir_name[i];
        flags->file_name_ind++;
    }
    flags->dir_name_ind = 0;
}

void flag_d_recognition(struct flags_list *flags)
{
    if (flags->d)
        d_flag(flags);
}
